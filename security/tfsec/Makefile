PORTNAME=	tfsec
DISTVERSIONPREFIX=	v
DISTVERSION=	1.28.11
CATEGORIES=	security

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Security scanner for Terraform
WWW=		https://aquasecurity.github.io/tfsec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	tfsec now is party of security/trivy
EXPIRATION_DATE=2024-11-26

USES=		go:1.22,modules

GO_MODULE=	github.com/aquasecurity/tfsec
GO_TARGET=	./cmd/${PORTNAME}

GO_BUILDFLAGS=	-ldflags="version.Version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
