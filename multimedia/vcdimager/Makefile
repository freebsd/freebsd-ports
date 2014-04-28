# Created by: Harold Gutch <logix@foobar.franken.de>
# $FreeBSD$

PORTNAME=	vcdimager
PORTVERSION=	0.7.24
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	vcdimager

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GNU VCDImager/VCDRip -- The GNU VideoCD Image Maker/Ripping Tool

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libcdio.so:${PORTSDIR}/sysutils/libcdio

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool:oldver pathfix pkgconfig
USE_LDCONFIG=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		vcdimager vcdxrip vcd-info

post-patch:
	@${REINPLACE_CMD} -e 's|libvcd||' ${WRKSRC}/libvcdinfo.pc.in

.include <bsd.port.mk>
