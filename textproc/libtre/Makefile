# ex:ts=8
# Ports collection makefile for:	libtre
# Date created:			Oct 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libtre
PORTVERSION=	0.7.6
CATEGORIES=	textproc
MASTER_SITES=	http://laurikari.net/tre/
DISTNAME=	tre-${PORTVERSION}

MAINTAINER=	bf1783@gmail.com
COMMENT=	A lightweight fully POSIX compliant regexp matching library

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	NLS "native language support" off \
		OPTIMIZED_CFLAGS "append optimization flags to CFLAGS" off \
		PGO "Enable Profile-Guided Optimization" off

MAN1=	tre_agrep.1

.include <bsd.port.pre.mk>

.if defined(WITH_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-Wuninitialized -ffast-math -finline-functions \
		-fomit-frame-pointer -fexpensive-optimizations \
		-fforce-mem -fforce-addr -O3
.endif

.if defined(WITH_PGO)
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fprofile-generate" \
		LDFLAGS="${LDFLAGS} -fprofile-generate"
.else
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
.endif

post-patch:
	${MV} ${WRKSRC}/doc/agrep.1.in ${WRKSRC}/doc/tre_agrep.1.in
	${REINPLACE_CMD} -e 's;agrep\.1;tre_agrep\.1;g' ${WRKSRC}/configure \
	${WRKSRC}/tre.spec.in ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's;agrep;tre_agrep;g' ${WRKSRC}/tests/agrep/*.ok

.if defined(WITH_PGO)
.if target(pre-build)
.error Makefile error since pre-build target has already been defined
.endif
pre-build: pgo
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in tre-api.html tre-syntax.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

regression-test: build
	@(cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} check )

.if defined(WITH_PGO)
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
.endif # if defined(WITH_PGO)

.include <bsd.port.post.mk>
