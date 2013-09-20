# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	mailzu
DISTVERSION=	0.8rc3
PORTREVISION=	2
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

NO_INSTALL_MANPAGES=	yes

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MIMAP}
USE_PHP+=	imap
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

do-install:
	@${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} -m 755 ${WWWDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.php* ${WRKSRC}/*.js* ${WRKSRC}/*.css* ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "config contrib img lang lib templates" \
		${WWWDIR} "! -name *.orig"
	@cd ${WRKSRC} && ${COPYTREE_BIN} scripts ${WWWDIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/CHANGELOG ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
	@${CHMOD} 644 ${WWWDIR}/config/config.php.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
