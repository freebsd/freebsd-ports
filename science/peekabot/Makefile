# New ports collection makefile for:	peekabot
# Date created:		21 June 2009
# Whom:			chris@officialunix.com
#
# $FreeBSD$
#

PORTNAME=	peekabot
PORTVERSION=	0.6.0
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	chris@officialunix.com
COMMENT=	Distributed real-time 3D visualization tool for robotics researchers

LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost \
		xerces-c.27:${PORTSDIR}/textproc/xerces-c2\
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	4.2+

.include <bsd.port.mk>
