# New ports collection makefile for:	vcdimager
# Date created:				16 April 2001
# Whom:					Harold Gutch <logix@foobar.franken.de>
#
# $FreeBSD$

PORTNAME=	vcdimager
PORTVERSION=	0.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.hvrlab.org/pub/vcdimager/vcdimager-0.6/

MAINTAINER=	logix@foobar.franken.de

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	vcdimager.1 vcdrip.1

.include <bsd.port.mk>
