# Created by: Scott Flatman <sf@dsinw.com>
# $FreeBSD$

PORTNAME=	maxima
PORTVERSION=	5.44.0
PORTREVISION=	10
CATEGORIES=	math lisp tk
MASTER_SITES=	SF/maxima/Maxima-source/${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Symbolic mathematics program

LICENSE=				GPLv2 MAXIMAEXTRACLAUSE
LICENSE_COMB=				multi
LICENSE_NAME_MAXIMAEXTRACLAUSE=		Maxima extra clause
LICENSE_FILE_MAXIMAEXTRACLAUSE=		${FILESDIR}/license-extra-clause.txt
LICENSE_PERMS_MAXIMAEXTRACLAUSE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_FreeBSD_13_powerpc64=	fails to build: unhandled lisp initialization error

RUN_DEPENDS=	gnuplot:math/gnuplot \
		rlwrap:devel/rlwrap

USES=		autoreconf gmake makeinfo shared-mime-info

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	PYTHON=dummy

INFO=		imaxima maxima xmaxima abs_integrate drawutils kovacicODE logic

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
PORTDOCS=	*
PORTDATA=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES DOCS NOUSERINIT MANPAGES SAGE TEST XMAXIMA
OPTIONS_SINGLE=		LISP
OPTIONS_SINGLE_LISP=	CCL CMUCL ECL SBCL

OPTIONS_DEFAULT=	ECL NOUSERINIT MANPAGES SAGE TEST XMAXIMA
OPTIONS_SUB=		yes

CCL_DESC=		Build with Clozure Common Lisp
CCL_BUILD_DEPENDS=	ccl:lang/ccl
CCL_RUN_DEPENDS=	ccl:lang/ccl
CCL_CONFIGURE_ON=	--with-ccl=ccl
CCL_PLIST_SUB=		BINDIR=binary-openmcl BINNAME=maxima.image

CMUCL_DESC=		Build with CMU Common Lisp
CMUCL_BUILD_DEPENDS=	lisp:lang/cmucl
CMUCL_RUN_DEPENDS=	lisp:lang/cmucl
CMUCL_CONFIGURE_ON=	--enable-cmucl
CMUCL_PLIST_SUB=	BINDIR=binary-cmucl BINNAME=maxima_core

ECL_DESC=		Build with Embedabble Common Lisp
ECL_BUILD_DEPENDS=	ecl:lang/ecl
ECL_RUN_DEPENDS=	ecl:lang/ecl
ECL_LIB_DEPENDS=	libgmp.so:math/gmp	\
			libffi.so:devel/libffi	\
			libgc.so:devel/boehm-gc	\
			libgc-threaded.so:devel/boehm-gc-threaded
# libgc-threaded.so is really only used when ecl is built with THREADS on,
# which is the default. See https://reviews.freebsd.org/D24959 for more
# details.
ECL_CONFIGURE_ON=	--with-ecl=ecl
ECL_PLIST_SUB=		BINDIR=binary-ecl BINNAME=maxima

NOUSERINIT_DESC=		Do not load user init file for lisp (only for sbcl)
NOUSERINIT_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_maxima.in
NOUSERINIT_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-OFF-src_maxima.in

SAGE_DESC=		Build with patches from Sage (implies ECL)
SAGE_BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops
SAGE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-share_linearalgebra_matrixexp.lisp \
			${PATCHDIR}/extra-patch-src_grind.lisp \
			${PATCHDIR}/extra-patch-src_hayat.lisp \
			${PATCHDIR}/extra-patch-src_init-cl.lisp \
			${PATCHDIR}/extra-patch-src_maxima.system
SAGE_IMPLIES=		ECL

SBCL_DESC=		Build with Steel Bank Common Lisp
SBCL_BUILD_DEPENDS=	sbcl:lang/sbcl
SBCL_RUN_DEPENDS=	sbcl:lang/sbcl
SBCL_CONFIGURE_ON=	--enable-sbcl
SBCL_PLIST_SUB=		BINDIR=binary-sbcl BINNAME=maxima_core

TEST_TARGET=		check
TEST_BUILD_DEPENDS=	gnuplot:math/gnuplot \
			rlwrap:devel/rlwrap
TEST_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-OFF-Makefile.am

XMAXIMA_DESC=		Install xmaxima (implies DOCS and TEST)
XMAXIMA_IMPLIES=	DOCS TEST
XMAXIMA_USES=		tk
XMAXIMA_CONFIGURE_WITH=	wish=${WISH}
XMAXIMA_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-interfaces_Makefile.am

post-patch:
	${GREP} -Fe '.core' -l -r ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} 's;\.core;_core;g'
	${FIND} -X ${WRKSRC}/interfaces/xmaxima -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} "s;tclsh;${TCLSH};g"
	${REINPLACE_CMD} "s;/usr;${LOCALBASE};g" ${WRKSRC}/src/intl.lisp

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

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/info && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '-name maxima*\.html'

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} '-name *\.dem'

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/doc/man/maxima.1.gz ${STAGEDIR}${PREFIX}/man/man1

post-install-SAGE-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ecl
	${INSTALL_DATA} ${WRKSRC}/src/binary-ecl/maxima.fas \
		${STAGEDIR}${PREFIX}/lib/ecl

.include <bsd.port.mk>
