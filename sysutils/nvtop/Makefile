PORTNAME=	nvtop
DISTVERSION=	3.3.2
CATEGORIES=	sysutils graphics

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	GPU & Accelerator process monitoring
WWW=		https://github.com/Syllo/nvtop/

LICENSE=	GPLv3

BUILD_DEPENDS=	libdrm>0:graphics/libdrm \
		libsysinfo>0:devel/libsysinfo
LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=		cmake ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Syllo

.include <bsd.port.mk>
