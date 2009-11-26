# New ports collection makefile for:	peekabot
# Date created:		21 June 2009
# Whom:			chris@officialunix.com
#
# $FreeBSD$
#

PORTNAME=	peekabot
PORTVERSION=	0.7.2
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.7.x/ \
		http://distfiles.officialunix.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed real-time 3D visualization tool for robotics researchers

LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost-libs \
		xerces-c.27:${PORTSDIR}/textproc/xerces-c2\
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	4.2+

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
