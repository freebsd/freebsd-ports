PORTNAME=	mongrel2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.2
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Is an application, language, and network arch
WWW=		https://mongrel2.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	BROKEN for more than 2 years on all platforms after the EOL of 12
EXPIRATION_DATE=	2024-01-01
BROKEN_armv6=	does not build: src/task/task.c:66:11: error: no member named 'arm_r0' in 'mcontext_t'
BROKEN_armv7=	does not build: src/task/task.c:66:11: error: no member named 'arm_r0' in 'mcontext_t'
BROKEN_mips=	does not build (tests segfault)
BROKEN_mips64=	does not build (tests segfault)
BROKEN_powerpc64=	does not build (tests segfault)
BROKEN_FreeBSD_13=	ld: error: duplicate symbol: m2program
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: m2program

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		gmake localbase:ldflags sqlite tar:bzip2
USE_GITHUB=	yes
GH_TUPLE=	ARMmbed:mbedtls:8254ed2:x/src/mbedtls

MAKE_ARGS+=	-f localmbedtls.mak
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	freebsd
TEST_ARGS=	${MAKE_ARGS}
TEST_ENV=	${MAKE_ENV} OPTFLAGS=-I${LOCALBASE}/include
TEST_TARGET=	tests # tests fail on 12: Invalid system call

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_LIST=	bbs \
		configs \
		kegogi \
		python \
		ws \
		chat \
		http_0mq \
		mp3stream \
		tornado \
		zcov

post-patch:
	@${REINPLACE_CMD} -e 's#fdclose#my_fdclose#g' ${WRKSRC}/src/*.c \
		${WRKSRC}/src/task/*.[ch] ${WRKSRC}/tests/*.c \
		${WRKSRC}/tools/filters/*.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mongrel2/*/*.so
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for example in ${EXAMPLES_LIST}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${example} ${STAGEDIR}/${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
