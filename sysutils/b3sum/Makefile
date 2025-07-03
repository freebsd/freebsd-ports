PORTNAME=	b3sum
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line implementation of the BLAKE3 hash function
WWW=		https://github.com/BLAKE3-team/BLAKE3

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE_A2

USES=		cargo

WRKSRC_SUBDIR=	b3sum

PLIST_FILES=	bin/b3sum

USE_GITHUB=	yes
GH_ACCOUNT=	BLAKE3-team
GH_PROJECT=	BLAKE3

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64
CARGO_FEATURES=	neon
.endif

.include <bsd.port.mk>
