# New ports collection makefile for:	erwin
# Date created:			31 July 1999
# Whom:				Jim Mock <jimFreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	erwn
PORTVERSION=	0.3.1
CATEGORIES=	www editors
MASTER_SITES=	http://lisas.de/erwin/legacy/
DISTNAME=	erwin-${PORTVERSION}

MAINTAINER=	jim@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/erwin"
	@${MKDIR} ${PREFIX}/share/doc/erwin && ${CHMOD} a+rx ${PREFIX}/share/doc/erwin
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/erwin
.endif

.include <bsd.port.mk>
