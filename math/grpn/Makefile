# New ports collection makefile for:	grpn
# Version required:			1.1.0
# Date created:				25 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	grpn-1.1.0
CATEGORIES=	math gnome
MASTER_SITES=	http://wilkins.ne.mediaone.net/grpn/

MAINTAINER=	jedgar@fxp.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

ALL_TARGET=
USE_X_PREFIX=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
MAKE_ENV+=	GTK_CONFIG=${GTK_CONFIG} \
		X11BASE=${X11BASE}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/grpn ${PREFIX}/bin

.include <bsd.port.mk>
