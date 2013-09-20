# Created by: Harold Gutch <logix@foobar.franken.de>
# $FreeBSD$

PORTNAME=	vcdimager
PORTVERSION=	0.7.24
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	vcdimager

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GNU VCDImager/VCDRip -- The GNU VideoCD Image Maker/Ripping Tool

LICENSE=	GPLv2

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		xml2:${PORTSDIR}/textproc/libxml2 \
		cdio.13:${PORTSDIR}/sysutils/libcdio

USES=		pkgconfig pathfix
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	lthack
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		cdxa2mpeg.1 vcdimager.1 vcdxminfo.1 vcdxrip.1 vcdxgen.1 \
		vcdxbuild.1 vcd-info.1
INFO=		vcdimager vcdxrip vcd-info

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|libvcd||' ${WRKSRC}/libvcdinfo.pc.in

.include <bsd.port.mk>
