# New ports collection makefile for:	wmcpuload
# Date created:				18 Apr 2001
# Whom:					Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	wmcpuload
PORTVERSION=	0.0.3a
CATEGORIES=	sysutils
MASTER_SITES=	http://ports.tolkien.dk/

MAINTAINER=	boll@tolkien.dk

LIB_DEPENDS=	dockapp.1:${PORTSDIR}/x11-wm/libdockapp

WRKSRC=		${WRKDIR}/${DISTNAME}

ONLY_FOR_ARCHS=	i386

#USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NO_INSTALL_MANPAGES=	yes

.include <bsd.port.mk>
