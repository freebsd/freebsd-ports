# New ports collection makefile for:   vcdimager
# Date created:                                16 April 2001
# Whom:                                        Harold Gutch <logix@foobar.franken.de>
#
# $FreeBSD$

PORTNAME=	vcdimager
PORTVERSION=	0.7.14
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.vcdimager.org/pub/vcdimager/vcdimager-0.7_UNSTABLE/ \
		${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"GNU VCDImager/VCDRip -- The GNU VideoCD Image Maker/Ripping Tool"

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		cdxa2mpeg.1 vcdimager.1 vcdxminfo.1 vcdxrip.1 vcdxgen.1 \
		vcdxbuild.1 vcddebug.1 vcddump.1
INFO=		vcdimager vcddump vcdxrip

.include <bsd.port.mk>
