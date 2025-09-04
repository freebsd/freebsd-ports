PORTNAME=	timestamp-authority
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.8
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Service for issuing RFC 3161 timestamps
WWW=		https://sigstore.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/sigstore/timestamp-authority
GO_TARGET=	./cmd/fetch-tsa-certs \
		./cmd/timestamp-cli \
		./cmd/timestamp-server

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

.include <bsd.port.mk>
