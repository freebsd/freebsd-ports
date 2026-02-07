PORTNAME=	vcdimager
DISTVERSION=	2.0.1
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	GNU

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GNU VCDImager/VCDRip -- The GNU VideoCD Image Maker/Ripping Tool
WWW=		https://www.gnu.org/software/vcdimager/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libcdio.so:sysutils/libcdio

USES=		gmake gnome libtool localbase makeinfo pathfix pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		vcdimager vcdxrip vcd-info

.include <bsd.port.mk>
