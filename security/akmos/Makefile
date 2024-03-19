PORTNAME=	akmos
PORTVERSION=	0.7.2
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	melanhit@gmail.com
COMMENT=	Cryptographic library with low footprint
WWW=		https://github.com/melanhit/akmos

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Last release in 2018, no active development for years and no users in tree
EXPIRATION_DATE=2024-03-31

BUILD_DEPENDS=	as:devel/binutils

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	melanhit
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

# Fix build with clang11
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	ASM TEST BENCH
OPTIONS_DEFAULT=ASM
OPTIONS_SUB=	yes

ASM_CMAKE_ON=	-DAKMOS_USE_ASM:BOOL=TRUE
ASM_CMAKE_OFF=	-DAKMOS_USE_ASM:BOOL=FALSE

BENCH_CMAKE_ON=	-DAKMOS_ENABLE_BENCH:BOOL=TRUE
BENCH_CMAKE_OFF=-DAKMOS_ENABLE_BENCH:BOOL=FALSE
BENCH_DESC=	Install benchmark

TEST_CMAKE_ON=	-DAKMOS_ENABLE_TEST:BOOL=TRUE
TEST_CMAKE_OFF=	-DAKMOS_ENABLE_TEST:BOOL=FALSE

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=strict-prototypes
.endif

.include <bsd.port.post.mk>
