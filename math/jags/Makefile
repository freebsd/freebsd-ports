# Created by: Eric van Gyzen <vangyzen@stat.duke.edu>
# $FreeBSD$

PORTNAME=	mcmc-jags
PORTVERSION=	4.0.0
CATEGORIES=	math
MASTER_SITES=	SF/mcmc-jags/JAGS/${S}.x/Source/:1 \
		SF/mcmc-jags/Examples/${S}.x/:2 \
		SF/mcmc-jags/Manuals/2.x/:3 \
		SF/mcmc-jags/Manuals/${S}.x/:4
DISTFILES=	JAGS-${PORTVERSION}${EXTRACT_SUFX}:1
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES:M*[12]:C|:.*||}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Just Another Gibbs Sampler

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		bison compiler:features fortran gmake libtool localbase
USE_GCC=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/JAGS-${PORTVERSION}

PLIST_SUB=	MODULEVERSION=${S}
S=		${PORTVERSION:C|\..*||}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || make(makesum)
DISTFILES+=	jags_developer_manual.pdf:3 jags_installation_manual.pdf:4 \
		jags_user_manual.pdf:4
PORTDOCS=	${DISTFILES:M*[34]:C|:.*||}
.endif
.if ${PORT_OPTIONS:MEXAMPLES} || make(makesum)
DISTFILES+=	classic-bugs.tar.gz:2
PORTEXAMPLES=	*
.endif

.if exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == "atlas"
LIB_DEPENDS+=	libatlas.so:math/atlas
CONFIGURE_ARGS=	--with-lapack="-lalapack -lptcblas" --with-blas="-lptf77blas"
.elif ${WITH_BLAS} == "reference"
LIB_DEPENDS+=	libblas.so:math/blas
LIB_DEPENDS+=	liblapack.so:math/lapack
CONFIGURE_ARGS=	--with-lapack="-llapack" --with-blas="-lblas"
.else
IGNORE=		invalid value for WITH_BLAS: ${WITH_BLAS}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} \
		-e '/@WINDOWS_FALSE@bin_SCRIPTS =/s/jags/mcmc-&/' \
		-e '/CLEANFILES =/s/jags/mcmc-&/' \
		-e '/@WINDOWS_FALSE@jags:/s/jags/mcmc-&/' \
		-e '/@WINDOWS_FALSE@.*rm -f jags/s/jags/mcmc-&/' \
		-e '/@WINDOWS_FALSE@.*mv jags.tmp jags/s/jags/mcmc-&/2' \
		${WRKSRC}/src/terminal/Makefile.in
.if ${PORT_OPTIONS:MEXAMPLES}
	@${SED} -i '' -e '\|JAGS ?=|{s|jags|mcmc-&|;s|/usr/local|${PREFIX}|;}' \
		${WRKDIR}/classic-bugs/vol[12]/Makefile
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${_DISTDIR}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKDIR}/classic-bugs; ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endif

.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	${LOCALBASE}/lib/R/library/coda/R/coda.rdb:math/R-cran-coda

check test: install
.for i in 1 2
	@cd ${WRKDIR}/classic-bugs/vol${i}; ${SETENV} ${MAKE_ENV} \
	${MAKE_CMD} ${MAKE_ARGS} check
.endfor
	@${FIND} ${WRKDIR}/classic-bugs -type f -name check.log | ${SORT} | \
	${XARGS} -tI @  ${CAT} @

.endif
.include <bsd.port.mk>
