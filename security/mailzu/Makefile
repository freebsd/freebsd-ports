# New ports collection makefile for:	mailzu
# Date created:				20 July 2009
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	mailzu
DISTVERSION=	0.8rc3
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	MailZu_${DISTVERSION:S/rc/RC/}

MAINTAINER=	sahil@tandon.net
COMMENT=	A simple and intuitive web interface to manage amavisd-new quarantine

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

OPTIONS=	MYSQL	"Use MySQL database storage/auth backend (default)"	On \
		PGSQL	"Use PostgreSQL database/auth storage backend"		Off \
		IMAP	"Use IMAP auth backend"					Off \
		LDAP	"Use LDAP auth backend"					Off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_IMAP)
USE_PHP+=	imap
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.if !defined(WITH_MYSQL) && !defined(WITH_PGSQL)
IGNORE=	you must choose a SQL storage backend with 'make config'
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	@${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} -m 755 ${WWWDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.php* ${WRKSRC}/*.js* ${WRKSRC}/*.css* ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "config contrib img lang lib templates" ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} scripts ${WWWDIR}

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/CHANGELOG ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
	@${CHMOD} 644 ${WWWDIR}/config/config.php.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
