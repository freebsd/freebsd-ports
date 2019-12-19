# $FreeBSD$

PORTNAME=	nomad-pot-driver
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Nomad driver to support pot jails

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pot:sysutils/pot \
		nomad:sysutils/nomad

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	trivago
GH_SUBDIR=	src/github.com/trivago/nomad-pot-driver

GO_TARGET=	:${PREFIX}/libexec/nomad/plugins/nomad-pot-driver

PLIST_FILES=	libexec/nomad/plugins/nomad-pot-driver
SUB_FILES=	pkg-message

.include <bsd.port.mk>
