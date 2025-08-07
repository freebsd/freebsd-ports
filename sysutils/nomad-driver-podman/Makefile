PORTNAME=	nomad-driver-podman
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Nomad driver to support podman
WWW=		https://www.nomadproject.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nomad:sysutils/nomad \
		podman:sysutils/podman

USES=		go:1.24,modules
GO_MODULE=	github.com/hashicorp/nomad-driver-podman
GO_TARGET=	:${PREFIX}/libexec/nomad/plugins/nomad-driver-podman

SUB_FILES=	pkg-message
PLIST_FILES=	${PREFIX}/libexec/nomad/plugins/nomad-driver-podman

.include <bsd.port.mk>
