# New ports collection makefile for:	dotproject
# Date created:				12 April 2005
# Whom:					Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	dotproject
PORTVERSION=	2.1.5
CATEGORIES=	www devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/dotProject%20Version%20${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open Source Project Management tool

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PHP=	gd mysql session zlib
WANT_PHP_WEB=	yes
USE_APACHE=	1.3+

SUB_FILES=	pkg-message

OPTIONS=	LDAP "Enable ldap support" On

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
USE_PHP+=	ldap xml
.endif

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/* ${WWWDIR}
	${RM} ${WWWDIR}/locales/es
	${RM} ${WWWDIR}/locales/pt_br
	${MKDIR} ${WWWDIR}/files/temp
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
