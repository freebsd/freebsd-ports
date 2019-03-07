# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	mailzu
DISTVERSION=	0.8rc3
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/MailZu%200.8RC3
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	MailZu_${DISTVERSION:S/rc/RC/}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Simple and intuitive web interface to manage amavisd-new quarantine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/sbin/amavisd:security/amavisd-new \
		${PEARDIR}/DB.php:databases/pear-DB@${PHP_FLAVOR} \
		${PEARDIR}/Mail/mime.php:mail/pear-Mail_Mime@${PHP_FLAVOR} \
		${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR} \
		${PEARDIR}/Mail/mimeDecode.php:mail/pear-Mail_mimeDecode@${PHP_FLAVOR}

PEARDIR?=	${LOCALBASE}/share/pear
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message
NO_BUILD=	yes
NO_ARCH=	yes
USE_PHP=	sockets
USES=		php:flavors,web

OPTIONS_DEFINE=	IMAP LDAP DOCS
OPTIONS_MULTI=	SQL
OPTIONS_MULTI_SQL=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL
SQL_DESC=	SQL sotage backend
MYSQL_DESC=	Use MySQL database storage/auth backend (default)
PGSQL_DESC=	Use PostgreSQL database/auth storage backend
IMAP_DESC=	Use IMAP auth backend
LDAP_DESC=	Use LDAP auth backend

MYSQL_USE=	PHP=mysqli
PGSQL_USE=	PHP=pgsql
IMAP_USE=	PHP=imap
LDAP_USE=	PHP=ldap

PORTDOCS=	*

post-patch:
	${INSTALL_DATA} ${FILESDIR}/pl.*.php ${WRKSRC}/lang/

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/*.php ${WRKSRC}/*.js ${WRKSRC}/*.css ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "config contrib img lang lib templates" \
		${STAGEDIR}${WWWDIR} "! -name '*.orig'")
	(cd ${WRKSRC} && ${COPYTREE_BIN} scripts ${STAGEDIR}${WWWDIR})
	${CHMOD} 644 ${STAGEDIR}${WWWDIR}/config/config.php.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
