PORTNAME=	nomad-pot-driver
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	9
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Nomad driver to support pot jails
WWW=		https://www.nomadproject.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nomad:sysutils/nomad \
		pot>=0.16.0:sysutils/pot

USES=		go:1.21,modules
GO_MODULE=	github.com/bsdpot/nomad-pot-driver
GO_TARGET=	:${PREFIX}/libexec/nomad/plugins/nomad-pot-driver

SUB_FILES=	pkg-message
PLIST_FILES=	${PREFIX}/libexec/nomad/plugins/nomad-pot-driver

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

.include <bsd.port.mk>
