PORTNAME=	conmon
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.13
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	OCI container runtime monitor
WWW=		https://github.com/containers/conmon

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libglib-2.0.so:devel/glib20

USES=		gmake go:no_targets pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	containers

.include <bsd.port.mk>
