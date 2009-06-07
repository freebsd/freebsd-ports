# New ports collection makefile for:	maxima
# Date created:				Jun 26 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$
#

PORTNAME=	maxima
PORTVERSION=	5.18.1
PORTREVISION=	1
CATEGORIES=	math tk
MASTER_SITES=	SF

MAINTAINER=	bf1783@gmail.com
COMMENT=	Symbolic mathematics program

BUILD_DEPENDS=	${LOCALBASE}/bin/${LISPPORT}
PATCH_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	${LOCALBASE}/bin/${LISPPORT} \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

USE_TK =		84+
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
USE_AUTOTOOLS=		aclocal:110 autoconf:262
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--with-posix-shell=${LOCALBASE}/bin/bash \
			--with-wish=${WISH} \
			${LISPSELECT}

MAN1=	maxima.1
INFO=	maxima imaxima xmaxima

PLIST_SUB=	BINDIR=${BINDIRECTORY}
PLIST_SUB+=	LISPBIN=${LISPBINARY}
PLIST_SUB+=	MAXIMABIN=${MAXIMABINARY}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS=	CLISP "Build with Clisp" off \
		CMUCL "Build with CMU Common Lisp" off \
		GCL "Build with GNU Common Lisp" off \
		SBCL "Build with Steel Bank Common Lisp" on

.include <bsd.port.pre.mk>

# Lisp to build with. Define only ONE of these!
.if defined(WITH_CLISP) && defined(WITHOUT_CMUCL) && defined(WITHOUT_GCL) && defined(WITHOUT_SBCL)
LISPSELECT=	--enable-clisp
LISPPORT=	clisp:${PORTSDIR}/lang/clisp
BINDIRECTORY=	binary-clisp
LISPBINARY=	lisp.run
PLIST_SUB+=	LISPBINARY=""
MAXIMABINARY=	maxima.mem
.elif defined(WITHOUT_CLISP) && defined(WITH_CMUCL) && defined(WITHOUT_GCL) && defined(WITHOUT_SBCL)
LISPSELECT=	--enable-cmucl
LISPPORT=	lisp:${PORTSDIR}/lang/cmucl
BINDIRECTORY=	binary-cmucl
LISPBINARY=	lisp
PLIST_SUB+=	LISPBINARY=""
MAXIMABINARY=	maxima.core
.elif defined(WITHOUT_CLISP) && defined(WITHOUT_CMUCL) && defined(WITH_GCL) && defined(WITHOUT_SBCL)
LISPSELECT=	--enable-gcl
LISPPORT=	gcl:${PORTSDIR}/lang/gcl
BINDIRECTORY=	binary-gcl
#LISPBINARY is null so fudge this so deinstall works cleanly
PLIST_SUB+=	LISPBINARY="@comment "
MAXIMABINARY=	maxima
.elif defined(WITHOUT_CLISP) && defined(WITHOUT_CMUCL) && defined(WITHOUT_GCL) && defined(WITH_SBCL)
LISPSELECT=	--enable-sbcl
LISPPORT=	sbcl:${PORTSDIR}/lang/sbcl
BINDIRECTORY=	binary-sbcl
#LISPBINARY is null so fudge this so deinstall works cleanly
PLIST_SUB+=	LISPBINARY="@comment "
MAXIMABINARY=	maxima.core
.else
IGNORE=		define only one lisp
.endif

post-patch:
	${FIND} -X ${WRKSRC}/archive ${WRKSRC}/interfaces/xmaxima \
	 -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e "s;tclsh;${TCLSH};g"
	( cd ${WRKSRC}/doc/info ; ${LOCALBASE}/bin/bash ./fix_crlf ; \
	${LOCALBASE}/bin/bash ./fix_tab )

regression-test: build
	${LOCALBASE}/bin/bash ${WRKSRC}/maxima-local --batch-string='run_testsuite();'

.include <bsd.port.post.mk>
