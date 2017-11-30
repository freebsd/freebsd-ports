# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mongrel2
PORTVERSION=	1.7.5
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://mongrel2.org/static/downloads/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Is an application, language, and network arch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq2 \
		libsqlite3.so:databases/sqlite3

BROKEN_armv6=	does not build
BROKEN_armv7=	does not build: src/task/task.c:66:11: error: no member named 'arm_r0' in 'mcontext_t'
BROKEN_mips=	does not build (tests segfault)
BROKEN_mips64=	does not build (tests segfault)
BROKEN_powerpc64=	does not build (tests segfault)

USES=		gmake tar:bzip2
MAKE_FLAGS=	freebsd
EXAMPLES_LIST=	bbs \
		chat \
		configs \
		http_0mq \
		kegogi \
		mp3stream \
		procer \
		python \
		tornado \
		zcov
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's#fdclose#my_fdclose#g' ${WRKSRC}/src/*.c \
		${WRKSRC}/src/task/*.[ch] ${WRKSRC}/tests/*.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mongrel2/*/*.so
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for example in ${EXAMPLES_LIST}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${example} ${STAGEDIR}/${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
