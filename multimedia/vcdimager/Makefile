# Created by: Harold Gutch <logix@foobar.franken.de>
# $FreeBSD$

PORTNAME=	vcdimager
PORTVERSION=	0.7.24
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	vcdimager

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GNU VCDImager/VCDRip -- The GNU VideoCD Image Maker/Ripping Tool

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libcdio.so:${PORTSDIR}/sysutils/libcdio

USES=		gmake pkgconfig pathfix
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	lthack
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		vcdimager vcdxrip vcd-info

post-patch:
	@${REINPLACE_CMD} -e 's|libvcd||' ${WRKSRC}/libvcdinfo.pc.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvcdinfo.so.2

.include <bsd.port.mk>
