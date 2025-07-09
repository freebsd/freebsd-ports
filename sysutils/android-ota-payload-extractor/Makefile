PORTNAME=	android-ota-payload-extractor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
PORTREVISION=	9
CATEGORIES=	sysutils

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Android OTA payload extractor written in Go
WWW=		https://github.com/tobyxdd/android-ota-payload-extractor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	tobyxdd
GH_TUPLE=	golang:protobuf:v1.3.4:golang_protobuf/vendor/github.com/golang/protobuf \
		xi2:xz:48954b6210f8:xi2_xz/vendor/github.com/xi2/xz

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/android-ota-payload-extractor

.include <bsd.port.mk>
