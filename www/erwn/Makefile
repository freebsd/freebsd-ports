# New ports collection makefile for:	erwin
# Date created:			31 July 1999
# Whom:				Jim Mock <jimFreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	erwn
PORTVERSION= 	0.3.1
CATEGORIES=	www editors
MASTER_SITES=	http://www-stud.fht-esslingen.de/erwin/
DISTNAME=	erwin-${PORTNAME}

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes

post-install:
	@strip ${PREFIX}/bin/erwin
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/erwin"
	@${MKDIR} ${PREFIX}/share/doc/erwin && ${CHMOD} a+rx ${PREFIX}/share/doc/erwin
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/erwin
.endif

.include <bsd.port.mk>
