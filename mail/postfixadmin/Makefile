# Created by: Rob Evers <rob@debank.tv>

PORTNAME=	postfixadmin
DISTVERSIONPREFIX=	postfixadmin-
DISTVERSION=	3.4.dev.20210902
CATEGORIES=	mail www

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	PHP web-based management tool for Postfix virtual domains and users

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL-LICENSE.TXT

USES=		cpe php shebangfix
CPE_VENDOR=	postfix_admin_project
CPE_PRODUCT=	postfix_admin
USE_GITHUB=	yes
GH_TAGNAME=	cd73f275
USE_PHP=	mbstring openssl pcre session spl

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES+=	pkg-message
PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

OPTIONS_DEFINE=		DOCS IMAP VACATION
OPTIONS_DEFAULT=	IMAP MYSQL PGSQL SQLITE VACATION
OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE
OPTIONS_SUB=		yes

IMAP_DESC=	Support automated sub-folder creation for new mailboxes
VACATION_DESC=	Install virtual vacation postfix script

IMAP_USE=		PHP=imap
MYSQL_USE=		PHP=pdo_mysql
PGSQL_USE=		PHP=pdo_pgsql
SQLITE_USE=		PHP=pdo_sqlite
VACATION_RUN_DEPENDS=	p5-DBI>=1.634:databases/p5-DBI \
			p5-Email-Sender>=1.300031:mail/p5-Email-Sender \
			p5-Email-Simple>=1.998:mail/p5-Email-Simple \
			p5-Email-Valid>=0.12:mail/p5-Email-Valid \
			p5-Log-Log4perl>=0.26:devel/p5-Log-Log4perl \
			p5-MIME-EncWords>=0.040:mail/p5-MIME-EncWords \
			p5-Net-DNS>=1.32:dns/p5-Net-DNS \
			p5-Try-Tiny>=0.30:lang/p5-Try-Tiny
VACATION_USES=		perl5

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/templates_c
	${INSTALL_DATA} ${WRKSRC}/*.php ${STAGEDIR}${WWWDIR}
.for i in configs languages lib model public scripts templates tests
	(cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/${i})
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/ADDITIONS && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ADDITIONS)
.for i in GPL-LICENSE.TXT LICENSE.TXT password_expiration.sql postfixadmin.my.cnf
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor

do-install-DOCS-on:
	(cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.for i in CHANGELOG.TXT INSTALL.TXT README.md
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-VACATION-on:
	(cd ${WRKSRC}/VIRTUAL_VACATION && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/VIRTUAL_VACATION)

.include <bsd.port.mk>
