PORTNAME=	nvme-cli
DISTVERSION=	2.11.0.3
CATEGORIES=	sysutils

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Port of Linux nvme cli utility
WWW=		https://github.com/linux-nvme/nvme-cli

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash>0:shells/bash \
		freebsd-nvme-shim>0:devel/freebsd-nvme-shim
LIB_DEPENDS=	libnvme.so:devel/libnvme \
		libjson-c.so:devel/json-c

USES=		meson pkgconfig

ONLY_FOR_ARCHS=	aarch64 amd64

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_TAGNAME=	freebsd-${DISTVERSION}

CFLAGS+=	-I${LOCALBASE}/include/freebsd-nvme-shim

MESON_ARGS=	-Ddocs=man

.include <bsd.port.mk>
