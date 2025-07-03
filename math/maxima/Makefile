PORTNAME=	maxima
DISTVERSION=	5.47.0
PORTREVISION=	26
CATEGORIES=	math lisp tk
MASTER_SITES=	SF/maxima/Maxima-source/${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Symbolic mathematics program
WWW=		http://maxima.sourceforge.net/

LICENSE=	BSD3CLAUSE GPLv2 MAXIMAEXTRACLAUSE
LICENSE_COMB=	multi
LICENSE_NAME_MAXIMAEXTRACLAUSE=	Maxima extra clause
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSES/getopt-license.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_MAXIMAEXTRACLAUSE=	${FILESDIR}/license-extra-clause.txt
LICENSE_PERMS_MAXIMAEXTRACLAUSE=	dist-mirror dist-sell pkg-mirror \
					pkg-sell auto-accept

BUILD_DEPENDS=	coreutils>0:sysutils/coreutils
RUN_DEPENDS=	gnuplot:math/gnuplot \
		rlwrap:devel/rlwrap

USES=		autoreconf gmake makeinfo shared-mime-info

GNU_CONFIGURE=	yes

TEST_TARGET=	check

BINARY_ALIAS=	expr=gexpr

INFO=		imaxima maxima xmaxima abs_integrate drawutils kovacicODE logic \
		nelder_mead symplectic_ode

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES MANPAGES NOUSERINIT SAGE TEST XMAXIMA
OPTIONS_DEFAULT=	ECL MANPAGES NOUSERINIT SAGE TEST XMAXIMA
OPTIONS_SINGLE=		LISP
OPTIONS_SINGLE_LISP=	CCL ECL SBCL

OPTIONS_SUB=	yes

CCL_DESC=		Build with Clozure Common Lisp
ECL_DESC=		Build with Embedabble Common Lisp
NOUSERINIT_DESC=	Do not load user init file for lisp (only for sbcl)
SAGE_DESC=		Build with patches from Sage (implies ECL)
SBCL_DESC=		Build with Steel Bank Common Lisp
XMAXIMA_DESC=		Install xmaxima (implies DOCS and TEST)

CCL_BUILD_DEPENDS=	ccl:lang/ccl
CCL_RUN_DEPENDS=	ccl:lang/ccl
CCL_CONFIGURE_ON=	--with-ccl=ccl
CCL_PLIST_SUB=		BINDIR=binary-openmcl \
			BINNAME=maxima.image
CCL_VARS=		NO_ARCH=yes

ECL_BUILD_DEPENDS=	ecl:lang/ecl
ECL_LIB_DEPENDS=	libffi.so:devel/libffi \
			libgc-threaded.so:devel/boehm-gc-threaded \
			libgc.so:devel/boehm-gc \
			libgmp.so:math/gmp
ECL_RUN_DEPENDS=	ecl:lang/ecl
# libgc-threaded.so is really only used when ecl is built with THREADS on,
# which is the default. See https://reviews.freebsd.org/D24959 for more
# details.
ECL_CONFIGURE_ON=	--with-ecl=ecl
ECL_PLIST_SUB=		BINDIR=binary-ecl \
			BINNAME=maxima

NOUSERINIT_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-nouserinit-src_maxima.in

SAGE_IMPLIES=		ECL
SAGE_BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops
SAGE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-share_linearalgebra_matrixexp.lisp \
			${PATCHDIR}/extra-patch-src_grind.lisp \
			${PATCHDIR}/extra-patch-src_hayat.lisp \
			${PATCHDIR}/extra-patch-src_init-cl.lisp

SBCL_BUILD_DEPENDS=	sbcl:lang/sbcl
SBCL_RUN_DEPENDS=	sbcl:lang/sbcl
SBCL_CONFIGURE_ON=	--enable-sbcl
SBCL_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-sbcl-src_maxima.in
SBCL_PLIST_SUB=		BINDIR=binary-sbcl \
			BINNAME=maxima_core
SBCL_VARS=		NO_ARCH=yes

TEST_BUILD_DEPENDS=	gnuplot:math/gnuplot \
			rlwrap:devel/rlwrap

XMAXIMA_IMPLIES=		DOCS TEST
XMAXIMA_USES=			tk
XMAXIMA_CONFIGURE_WITH=		wish=${WISH}
XMAXIMA_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-interfaces_Makefile.am

post-patch:
	${GREP} -Fe '.core' -l -r ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} 's;\.core;_core;g'
	${REINPLACE_CMD} "s;tclsh;${TCLSH};g" ${WRKSRC}/interfaces/xmaxima/Makefile.in
	${REINPLACE_CMD} "s;/usr;${LOCALBASE};g" ${WRKSRC}/src/intl.lisp

post-patch-TEST-off:
	${REINPLACE_CMD} 's;tests;;' ${WRKSRC}/Makefile.am

post-patch-XMAXIMA-on:
	${REINPLACE_CMD} "s;%%DOCSDIR%%;/${DOCSDIR:S,/, ,g};" \
	${WRKSRC}/interfaces/xmaxima/Tkmaxima/Paths.tcl

post-configure:
	${REINPLACE_CMD} '/ld-flags/s|" |"|' ${WRKSRC}/src/autoconf-variables.lisp
	${REINPLACE_CMD} '/ld-flags/s| ")|")|' ${WRKSRC}/src/autoconf-variables.lisp

pre-build-CCL-on:
	cd ${WRKSRC}/src/ && ${MKDIR} binary-ccl && ${LN} -s binary-ccl binary-openmcl

post-build-MANPAGES-on:
	${GZIP_CMD} ${WRKSRC}/doc/man/maxima.1

post-install:
	for x in "" "-1" "-2" "-3"; do ${INSTALL_MAN} ${WRKSRC}/doc/info/maxima.info$$x ${STAGEDIR}${PREFIX}/${INFO_PATH}; done
	${INSTALL_MAN} ${WRKSRC}/doc/info/maxima-index.lisp ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/doc/info/maxima-index-html.lisp ${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/info && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '-name maxima*\.html'

post-install-ECL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ecl
	${INSTALL_LIB} ${WRKSRC}/src/binary-ecl/maxima.fas \
		${STAGEDIR}${PREFIX}/lib/ecl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/maxima/${PORTVERSION}/binary-ecl/maxima

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} '-name *\.dem'

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/doc/man/maxima.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/maxima.1.gz

.include <bsd.port.mk>
