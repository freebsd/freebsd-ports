PORTNAME=	nvme-cli
PORTVERSION=	2.11
CATEGORIES=	sysutils

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Port of Linux nvme cli utility
WWW=		https://github.com/linux-nvme/nvme-cli

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	bash>0:shells/bash \
		freebsd-nvme-shim>0:devel/freebsd-nvme-shim \
		swig:devel/swig
LIB_DEPENDS=	libnvme.so:devel/libnvme

USES=		meson pkgconfig

MESON_ARGS=	-Ddocs=man -Djson-c=disabled
CXXFLAGS+=	-I${LOCALBASE}/include/freebsd-nvme-shim
CFLAGS+=	-I${LOCALBASE}/include/freebsd-nvme-shim

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_TAGNAME=	freebsd-${PORTVERSION}

.include <bsd.port.mk>
