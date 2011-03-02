# New ports collection makefile for:	peekabot
# Date created:		21 June 2009
# Whom:			chris@officialunix.com
#
# $FreeBSD$
#

PORTNAME=	peekabot
PORTVERSION=	0.8.4
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}.x/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed real-time 3D visualization tool for robotics researchers

LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost-libs \
		xerces-c.27:${PORTSDIR}/textproc/xerces-c2 \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		gtkglextmm-x11-1.2:${PORTSDIR}/x11-toolkits/gtkglextmm

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="`fltk-config --ldflags`" \
		CPPFLAGS="`fltk-config --cflags`"
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
#Internal compiler error with < 4.4
USE_GCC=	4.4+

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not compile with boost on sparc64
.endif

.include <bsd.port.post.mk>
