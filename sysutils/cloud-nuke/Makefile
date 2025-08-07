PORTNAME=	cloud-nuke
DISTVERSIONPREFIX=	v
DISTVERSION=	0.41.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Cleaning up your cloud accounts
WWW=		https://github.com/gruntwork-io/cloud-nuke

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe go:1.23,modules

CPE_VENDOR=	gruntwork-io
GO_MODULE=	github.com/gruntwork-io/cloud-nuke
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.VERSION=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
