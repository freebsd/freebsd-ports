# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	mailzu
DISTVERSION=	0.8rc3
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/MailZu%200.8RC3
DISTNAME=	MailZu_${DISTVERSION:S/rc/RC/}

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Simple and intuitive web interface to manage amavisd-new quarantine

RUN_DEPENDS=	${LOCALBASE}/sbin/amavisd:${PORTSDIR}/security/amavisd-new \
		${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime \
		${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/Mail/mimeDecode.php:${PORTSDIR}/mail/pear-Mail_mimeDecode

PEARDIR?=	${LOCALBASE}/share/pear
SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES=	pkg-message
NO_BUILD=	yes
USE_PHP=	sockets
WANT_PHP_WEB=	yes

OPTIONS_DEFINE=	IMAP LDAP DOCS
OPTIONS_MULTI=	SQL
OPTIONS_MULTI_SQL=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL
SQL_DESC=	SQL sotage backend
MYSQL_DESC=	Use MySQL database storage/auth backend (default)
PGSQL_DESC=	Use PostgreSQL database/auth storage backend
IMAP_DESC=	Use IMAP auth backend
LDAP_DESC=	Use LDAP auth backend

MYSQL_USE=	PHP=mysql
PGSQL_USE=	PHP=pgsql
IMAP_USE=	PHP=imap
LDAP_USE=	PHP=ldap

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/*.php* ${WRKSRC}/*.js* ${WRKSRC}/*.css* ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "config contrib img lang lib templates" \
		${STAGEDIR}${WWWDIR} "! -name *.orig")
	(cd ${WRKSRC} && ${COPYTREE_BIN} scripts ${STAGEDIR}${WWWDIR})

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	${CHMOD} 644 ${STAGEDIR}${WWWDIR}/config/config.php.sample

.include <bsd.port.mk>
