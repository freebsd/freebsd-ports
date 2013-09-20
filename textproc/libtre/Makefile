# Created by: ijliao
# $FreeBSD$

PORTNAME=	libtre
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://laurikari.net/tre/ \
		LOCAL/bf
DISTNAME=	tre-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Lightweight fully POSIX compliant regexp matching library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_BZIP2=	yes
USES=	pathfix pkgconfig
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS+=	--enable-static
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS OPTIMIZED_CFLAGS PGO DOCS

MAN1=	tre_agrep.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-Wuninitialized -ffast-math -finline-functions \
		-fomit-frame-pointer -fexpensive-optimizations \
		-fforce-mem -fforce-addr -O3
.endif

.if ${PORT_OPTIONS:MPGO}
LDFLAGS+=	-fprofile-generate
CFLAGS+=	-fprofile-generate
.endif

post-patch:
	${MV} ${WRKSRC}/doc/agrep.1.in ${WRKSRC}/doc/tre_agrep.1.in
	${REINPLACE_CMD} -e 's;agrep\.1;tre_agrep\.1;g' ${WRKSRC}/configure \
	${WRKSRC}/tre.spec.in ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's;agrep;tre_agrep;g' ${WRKSRC}/tests/agrep/*.ok

.if ${PORT_OPTIONS:MPGO}
.if target(pre-build)
.error Makefile error since pre-build target has already been defined
.endif
pre-build: pgo
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in tre-api.html tre-syntax.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

regression-test: build
	@(cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} check )

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
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET})

pgo-run:
# Check everything to generate profiling information.
	@-(cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} check)

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
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE} clean)
. endfor
# Only remove some files from lib to preserve profiling information.
	@${FIND} -E ${BUILD_WRKSRC}/lib -iregex ".*\.(a|la|lai|lo|o|so|so\..*)$$" \
		-exec ${RM} -f {} \;
.endif # if ${PORT_OPTIONS:MPGO}

.include <bsd.port.post.mk>
