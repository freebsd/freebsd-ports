# Created by: ijliao
# $FreeBSD$

PORTNAME=	libtre
PORTVERSION=	0.8.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://laurikari.net/tre/ \
		LOCAL/bf
DISTNAME=	tre-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight fully POSIX compliant regexp matching library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS OPTIMIZED_CFLAGS PGO DOCS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
OPTIMIZED_CFLAGS_CFLAGS= \
		-Wuninitialized -ffast-math -finline-functions \
		-fomit-frame-pointer -fexpensive-optimizations -O3
PGO_CFLAGS=	-fprofile-generate
PGO_LDFLAGS=	-fprofile-generate

.include <bsd.port.options.mk>

post-patch: .SILENT
	${MV} ${WRKSRC}/doc/agrep.1.in ${WRKSRC}/doc/tre_agrep.1.in
	${REINPLACE_CMD} -e 's;agrep\.1;tre_agrep\.1;g' ${WRKSRC}/configure \
	${WRKSRC}/tre.spec.in ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's;agrep;tre_agrep;g' ${WRKSRC}/tests/agrep/*.ok

.if ${PORT_OPTIONS:MPGO}
pre-build: pgo
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in tre-api.html tre-syntax.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

regression-test: build
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check )

.if ${PORT_OPTIONS:MPGO}
pgo: pgo-pre-build pgo-build pgo-run pgo-post-run pgo-clean

pgo-pre-build:
	@${FIND} ${BUILD_WRKSRC} -type f -name Makefile -exec \
		${REINPLACE_CMD} -E \
			-e 's,^((C|LD)FLAGS[[:space:]]*=.*)-fprofile-generate,\1,' \
			-e 's,^(CFLAGS[[:space:]]*=.*)-fprofile-use,\1,' \
			-e 's,^((C|LD)FLAGS[[:space:]]*=.*)$$,\1 -fprofile-generate,' \
			{} \;

pgo-build:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET})

pgo-run:
# Check everything to generate profiling information.
	@-(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check)

pgo-post-run:
	@${FIND} ${BUILD_WRKSRC} -type f -name Makefile -exec \
		${REINPLACE_CMD} -E \
			-e 's,^((C|LD)FLAGS[[:space:]]*=.*)-fprofile-generate,\1,' \
			-e 's,^(CFLAGS[[:space:]]*=.*)-fprofile-use,\1,' \
			-e 's,^(CFLAGS[[:space:]]*=.*)$$,\1 -fprofile-use,' \
			{} \;
	@${REINPLACE_CMD} -E \
		-e 's,-fprofile-generate,-fprofile-use,g' \
		${CONFIGURE_WRKSRC}/config.status \
		${CONFIGURE_WRKSRC}/libtool
	@${REINPLACE_CMD} -E \
		-e 's,-fprofile-generate,,g' \
		${BUILD_WRKSRC}/tre.pc

pgo-clean:
# Selectively clean some directories.
. for dir in src tests
	@(cd ${BUILD_WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} clean)
. endfor
# Only remove some files from lib to preserve profiling information.
	@${FIND} -E ${BUILD_WRKSRC}/lib -iregex ".*\.(a|la|lai|lo|o|so|so\..*)$$" \
		-exec ${RM} {} \;
.endif # if ${PORT_OPTIONS:MPGO}

.include <bsd.port.mk>
