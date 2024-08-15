PORTNAME=	conmon
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.12
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	OCI container runtime monitor
WWW=		https://github.com/containers/conmon

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libglib-2.0.so:devel/glib20

USES=		gmake go:no_targets pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	containers

.include <bsd.port.mk>
