# New ports collection makefile for:	wmcpuload
# Date created:				18 Apr 2001
# Whom:					Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	wmcpuload
PORTVERSION=	0.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/ \
		http://ports.tolkien.dk/
DISTNAME=	WMCPULoad-${PORTVERSION}

MAINTAINER=	boll@tolkien.dk

LIB_DEPENDS=	dockapp.1:${PORTSDIR}/x11-wm/libdockapp

WRKSRC=		${WRKDIR}/${DISTNAME}

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NO_INSTALL_MANPAGES=	yes

.include <bsd.port.mk>
