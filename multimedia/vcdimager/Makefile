# Created by: Harold Gutch <logix@foobar.franken.de>
# $FreeBSD$

PORTNAME=	vcdimager
PORTVERSION=	0.7.24
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	GNU

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GNU VCDImager/VCDRip -- The GNU VideoCD Image Maker/Ripping Tool

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libcdio.so:${PORTSDIR}/sysutils/libcdio

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

INFO=		vcdimager vcdxrip vcd-info

.include <bsd.port.mk>
