PORTNAME=	ipaddr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	net

MAINTAINER=	ab@astral.blue
COMMENT=	Command-line IP address manipulation tool
WWW=		https://github.com/astralblue/ipaddr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	requires compiler support for __uint128_t (64-bit only)

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	astralblue

PLIST_FILES=	bin/ipaddr \
		share/man/man1/ipaddr.1.gz

.include <bsd.port.mk>
