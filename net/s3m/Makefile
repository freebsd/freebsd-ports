PORTNAME=	s3m
DISTVERSION=	0.13.1
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	nbari@tequila.io
COMMENT=	CLI for streams of data in S3 buckets
WWW=		https://s3m.stream

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	needs SSE or SSE2 type extensions to compile

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo ssl
USE_GITHUB=	yes

PORTSCOUT=	limit:[0-9.]+

PLIST_FILES=	bin/s3m

.include <bsd.port.mk>
