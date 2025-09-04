PORTNAME=	buildah
DISTVERSIONPREFIX=	v
DISTVERSION=	1.41.3
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Manage Pods, Containers and Container Images
WWW=		https://buildah.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	as:devel/binutils \
		bash:shells/bash \
		go-md2man:textproc/go-md2man \
		gsed:textproc/gsed
LIB_DEPENDS=	libgpgme.so:security/gpgme
RUN_DEPENDS=	containernetworking-plugins>=0:net/containernetworking-plugins \
		containers-common>=0:sysutils/containers-common \
		ocijail:sysutils/ocijail

USES=		gmake go:no_targets,1.23 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	containers
GH_PROJECT=	buildah
INSTALL_TARGET=	install install.completions

.include <bsd.port.mk>
