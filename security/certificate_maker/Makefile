PORTNAME=	certificate_maker
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Certificate creation utility for Fulcio
WWW=		https://www.sigstore.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	sigstore

GO_MODULE=	github.com/sigstore/fulcio
GO_BUILDFLAGS=	-ldflags="-X \
		sigs.k8s.io/release-utils/version.gitVersion=${DISTVERSIONPREFIX}${DISTVERSION}"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
