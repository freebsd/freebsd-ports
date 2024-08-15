PORTNAME=	buildah
DISTVERSIONPREFIX=	v
DISTVERSION=	1.36.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Manage Pods, Containers and Container Images
WWW=		https://buildah.io/

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		go-md2man:textproc/go-md2man \
		gsed:textproc/gsed \
		as:devel/binutils
LIB_DEPENDS=	libgpgme.so:security/gpgme
RUN_DEPENDS=	containernetworking-plugins>=0:net/containernetworking-plugins \
		containers-common>=0:sysutils/containers-common \
		ocijail:sysutils/ocijail

USES=		gmake go:no_targets pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	containers
GH_PROJECT=	buildah
INSTALL_TARGET=	install install.completions

.include <bsd.port.mk>
