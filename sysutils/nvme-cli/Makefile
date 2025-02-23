PORTNAME=	nvme-cli
DISTVERSION=	2.11
CATEGORIES=	sysutils

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Port of Linux nvme cli utility
WWW=		https://github.com/linux-nvme/nvme-cli

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash>0:shells/bash \
		freebsd-nvme-shim>0:devel/freebsd-nvme-shim \
		swig:devel/swig
LIB_DEPENDS=	libnvme.so:devel/libnvme

USES=		meson pkgconfig

ONLY_FOR_ARCHS=	aarch64 amd64

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_TAGNAME=	freebsd-${DISTVERSION}

CFLAGS+=	-I${LOCALBASE}/include/freebsd-nvme-shim

MESON_ARGS=	-Ddocs=man \
		-Djson-c=disabled

.include <bsd.port.mk>
