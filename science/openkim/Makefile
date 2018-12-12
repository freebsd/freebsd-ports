# $FreeBSD$

PORTNAME=	openkim
PORTVERSION=	1.1.1
PORTREVISION=	8
CATEGORIES=	science
MASTER_SITES=	http://s3.openkim.org/openkim-api/
DISTNAME=	${PORTNAME}-api-v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Knowledgebase of Interatomic Models

LICENSE=	CDDL

MAKE_ENV+=	KIM_DIR=${WRKSRC}

USES=		gmake fortran tar:tgz

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.options.mk>

# Is there a better way to detect 32-bit systems?
.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == mips || ${ARCH} == powerpc
MAKE_ENV+=	KIM_SYSTEM32="yes"
.endif

post-patch:
	${REINPLACE_CMD} \
		-e "s|gcc|${CC}|g" \
		-e "s|g++|${CXX}|g" \
		-e "s|= gfortran|= ${FC}|g" \
		-e "s|-O3|${CFLAGS}|g" \
		-e "s|LINKLIBFLAG =|LINKLIBFLAG = ${LDFLAGS}|" \
		${WRKSRC}/KIM_API/GNU_compiler_settings.mk

# Required for main build to succeed
pre-build:
	(cd ${WRKSRC} && ${MAKE_CMD} KIM_DIR=${WRKSRC} examples)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/include/KIM_API
	${INSTALL_DATA} ${WRKSRC}/KIM_API/libkim.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/KIM_API/*.h ${STAGEDIR}${PREFIX}/include/KIM_API

do-test:
	(cd ${WRKSRC}/TESTs/ex_test_Ar_free_cluster_CLUSTER_F90 && \
		${ECHO_CMD} "ex_model_Ar_P_MLJ_CLUSTER_C" | ./ex_test_Ar_free_cluster_CLUSTER_F90)

.include <bsd.port.mk>
