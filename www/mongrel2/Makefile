# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mongrel2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.2
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Is an application, language, and network arch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

BROKEN_armv6=	does not build: src/task/task.c:66:11: error: no member named 'arm_r0' in 'mcontext_t'
BROKEN_armv7=	does not build: src/task/task.c:66:11: error: no member named 'arm_r0' in 'mcontext_t'
BROKEN_mips=	does not build (tests segfault)
BROKEN_mips64=	does not build (tests segfault)
BROKEN_powerpc64=	does not build (tests segfault)

USES=		gmake localbase:ldflags sqlite tar:bzip2
USE_GITHUB=	yes
GH_TUPLE=	ARMmbed:mbedtls:8254ed2:x/src/mbedtls
ALL_TARGET=	freebsd
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
MAKE_JOBS_UNSAFE=	yes
MAKE_ARGS+=	-f localmbedtls.mak

TEST_TARGET=	tests # tests fail on 12: Invalid system call
TEST_ENV=	${MAKE_ENV} OPTFLAGS=-I${LOCALBASE}/include
TEST_ARGS=	${MAKE_ARGS}

OPTIONS_DEFINE=	EXAMPLES

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
