PORTNAME=	mailzu
DISTVERSION=	0.8rc3
PORTREVISION=	12
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/MailZu%200.8RC3
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	MailZu_${DISTVERSION:S/rc/RC/}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Simple and intuitive web interface to manage amavisd-new quarantine
WWW=		https://sourceforge.net/projects/mailzu/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/sbin/amavisd:security/amavisd-new \
		${PEARDIR}/DB.php:databases/pear-DB@${PHP_FLAVOR} \
		${PEARDIR}/Mail/mime.php:mail/pear-Mail_Mime@${PHP_FLAVOR} \
		${PEARDIR}/Mail/mimeDecode.php:mail/pear-Mail_mimeDecode@${PHP_FLAVOR} \
		${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR}

USES=		php:flavors,web
USE_PHP=	sockets
IGNORE_WITH_PHP=	81

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PLIST_SUB=	WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS IMAP LDAP
OPTIONS_DEFAULT=	MYSQL
OPTIONS_MULTI=		SQL
OPTIONS_MULTI_SQL=	MYSQL PGSQL

IMAP_DESC=	Use IMAP auth backend
LDAP_DESC=	Use LDAP auth backend
MYSQL_DESC=	Use MySQL database storage/auth backend (default)
PGSQL_DESC=	Use PostgreSQL database/auth storage backend
SQL_DESC=	SQL sotage backend

IMAP_USE=	PHP=imap
LDAP_USE=	PHP=ldap
MYSQL_USE=	PHP=mysqli
PGSQL_USE=	PHP=pgsql

PEARDIR?=	${LOCALBASE}/share/pear

post-patch:
	${INSTALL_DATA} ${FILESDIR}/pl.*.php ${WRKSRC}/lang/

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/*.php ${WRKSRC}/*.js ${WRKSRC}/*.css ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "config contrib img lang lib templates" \
		${STAGEDIR}${WWWDIR} "! -name '*.orig'")
	(cd ${WRKSRC} && ${COPYTREE_BIN} scripts ${STAGEDIR}${WWWDIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
