# New ports collection makefile for:   vcdimager
# Date created:                                16 April 2001
# Whom:                                        Harold Gutch <logix@foobar.franken.de>
#
# $FreeBSD$

PORTNAME=	vcdimager
PORTVERSION=	0.7.23
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	vcdimager

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GNU VCDImager/VCDRip -- The GNU VideoCD Image Maker/Ripping Tool

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		xml2:${PORTSDIR}/textproc/libxml2 \
		cdio.8:${PORTSDIR}/sysutils/libcdio

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gnomehack pkgconfig lthack
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		cdxa2mpeg.1 vcdimager.1 vcdxminfo.1 vcdxrip.1 vcdxgen.1 \
		vcdxbuild.1 vcd-info.1
INFO=		vcdimager vcdxrip vcd-info

post-patch:
	@${REINPLACE_CMD} -e 's|libvcd||' ${WRKSRC}/libvcdinfo.pc.in

.include <bsd.port.mk>
