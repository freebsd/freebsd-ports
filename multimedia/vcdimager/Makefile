PORTNAME=	vcdimager
PORTVERSION=	2.0.1
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	GNU

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GNU VCDImager/VCDRip -- The GNU VideoCD Image Maker/Ripping Tool
WWW=		https://www.gnu.org/software/vcdimager/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libxml2.so:textproc/libxml2 \
		libcdio.so:sysutils/libcdio

USES=		gmake libtool localbase makeinfo pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		vcdimager vcdxrip vcd-info

.include <bsd.port.mk>
