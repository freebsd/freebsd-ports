PORTNAME=	postfixadmin
DISTVERSIONPREFIX=	postfixadmin-
DISTVERSION=	3.4.dev.20211018
CATEGORIES=	mail www
.if defined(_PFA_LITE)
PKGNAMESUFFIX=	-lite${PHP_PKGNAMESUFFIX}
.else
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
.endif

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	PHP web-based management tool for Postfix virtual domains and users

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL-LICENSE.TXT

USES=		cpe php:flavors shebangfix
CPE_VENDOR=	postfix_admin_project
CPE_PRODUCT=	postfix_admin
USE_GITHUB=	yes
GH_TAGNAME=	d3bc1551
USE_PHP=	mbstring openssl pcre session spl

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES+=	pkg-message
PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

OPTIONS_DEFINE=		ADDONS DOCS IMAP
.if defined(_PFA_LITE)
OPTIONS_DEFAULT=	SQLITE
.else
OPTIONS_DEFAULT=	ADDONS IMAP SQLITE
.endif
OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE
OPTIONS_SUB=		yes

ADDONS_DESC=	Include add-ons and related Perl dependencies
IMAP_DESC=	Support automated sub-folder creation for new mailboxes

ADDONS_RUN_DEPENDS=	p5-DBI>=1.634:databases/p5-DBI \
			p5-Email-Sender>=1.300031:mail/p5-Email-Sender \
			p5-Email-Simple>=1.998:mail/p5-Email-Simple \
			p5-Email-Valid>=0.12:mail/p5-Email-Valid \
			p5-LockFile-Simple>=0.208:devel/p5-LockFile-Simple \
			p5-Log-Log4perl>=0.26:devel/p5-Log-Log4perl \
			p5-MIME-EncWords>=0.040:mail/p5-MIME-EncWords \
			p5-Net-DNS>=1.32:dns/p5-Net-DNS \
			p5-Try-Tiny>=0.30:lang/p5-Try-Tiny
ADDONS_USES=		gettext perl5
IMAP_USE=		PHP=imap
MYSQL_USE=		PHP=pdo_mysql
PGSQL_USE=		PHP=pdo_pgsql
SQLITE_USE=		PHP=pdo_sqlite

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/templates_c
	${INSTALL_DATA} ${WRKSRC}/*.php ${STAGEDIR}${WWWDIR}
.for i in configs languages lib model public scripts templates tests
	(cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/${i})
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
.for i in GPL-LICENSE.TXT LICENSE.TXT password_expiration.sql postfixadmin.my.cnf
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor

do-install-ADDONS-on:
	(cd ${WRKSRC}/ADDITIONS && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ADDITIONS)
	(cd ${WRKSRC}/VIRTUAL_VACATION && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/VIRTUAL_VACATION)

do-install-DOCS-on:
	(cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.for i in CHANGELOG.TXT INSTALL.TXT README.md
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
