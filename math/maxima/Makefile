# Created by: Scott Flatman <sf@dsinw.com>
# $FreeBSD$

PORTNAME=	maxima
PORTVERSION=	5.43.2
PORTREVISION=	3
CATEGORIES=	math lisp tk
MASTER_SITES=	SF/maxima/Maxima-source/${PORTVERSION}-source

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Symbolic mathematics program

LICENSE=				GPLv2 MAXIMAEXTRACLAUSE
LICENSE_COMB=				multi
LICENSE_NAME_MAXIMAEXTRACLAUSE=		Maxima extra clause
LICENSE_FILE_MAXIMAEXTRACLAUSE=		${FILESDIR}/license-extra-clause.txt
LICENSE_PERMS_MAXIMAEXTRACLAUSE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	gnuplot:math/gnuplot \
		rlwrap:devel/rlwrap

USES=		autoreconf gmake makeinfo shared-mime-info tk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	PYTHON=dummy

INFO=		imaxima maxima xmaxima abs_integrate drawutils kovacicODE logic

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
PORTDOCS=	*
PORTDATA=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES DOCS NOUSERINIT MANPAGES TEST
OPTIONS_SINGLE=		LISP
OPTIONS_SINGLE_LISP=	CCL CMUCL SBCL

OPTIONS_DEFAULT=	NOUSERINIT MANPAGES SBCL
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

NOUSERINIT_DESC=	Do not load user init file for lisp (only for sbcl)

SBCL_DESC=		Build with Steel Bank Common Lisp
SBCL_BUILD_DEPENDS=	sbcl:lang/sbcl
SBCL_RUN_DEPENDS=	sbcl:lang/sbcl
SBCL_CONFIGURE_ON=	--enable-sbcl
SBCL_PLIST_SUB=		BINDIR=binary-sbcl BINNAME=maxima_core

TEST_TARGET=	check
TEST_BUILD_DEPENDS=	gnuplot:math/gnuplot \
			rlwrap:devel/rlwrap
post-patch:
	${GREP} -Fe '.core' -l -r ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} 's;\.core;_core;g'
	${FIND} -X ${WRKSRC}/interfaces/xmaxima -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} "s;tclsh;${TCLSH};g"
	${REINPLACE_CMD} "s;/usr;${LOCALBASE};g" ${WRKSRC}/src/intl.lisp
	${REINPLACE_CMD} 's;demo;;' ${WRKSRC}/Makefile.am

post-patch-TEST-off:
	${REINPLACE_CMD} 's;tests;;' ${WRKSRC}/Makefile.am

pre-build-CCL-on:
	cd ${WRKSRC}/src/ && ${MKDIR} binary-ccl && ${LN} -s binary-ccl binary-openmcl

post-build-MANPAGES-on:
	${GZIP_CMD} ${WRKSRC}/doc/man/maxima.1

post-build-TEST-on: do-test

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

post-install-NOUSERINIT-on:
	${REINPLACE_CMD} 's;--end-runtime-options;--end-runtime-options --no-userinit;' ${STAGEDIR}${PREFIX}/bin/maxima

.include <bsd.port.mk>
