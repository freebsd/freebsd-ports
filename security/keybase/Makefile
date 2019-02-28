# $FreeBSD$

PORTNAME=	keybase
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keybase.io client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		go

GO_PKGNAME=	github.com/keybase/client/go
GO_TARGET=	-tags production ${GO_PKGNAME}/keybase
WRKSRC_SUBDIR=	go

PLIST_FILES=	bin/keybase

GH_PROJECT=	client
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/+build/ s|$$| freebsd|' ${WRKSRC}/client/platform_specific_ctl_commands_other.go
	@${REINPLACE_CMD} -e '/+build/ s|,amd64||' ${WRKSRC}/vendor/github.com/keybase/go-ps/process_freebsd.go

.include <bsd.port.mk>
