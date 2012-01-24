# New ports collection makefile for:	maxima
# Date created:				Jun 26 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$
#

PORTNAME=	maxima
PORTVERSION=	5.26.0
PORTREVISION=	1
CATEGORIES=	math lisp tk
MASTER_SITES=	SF/maxima/Maxima-source/${PORTVERSION}-source

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Symbolic mathematics program

LICENSE=		GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/${LISPPORT}
PATCH_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	${LOCALBASE}/bin/${LISPPORT} \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

USE_TK =		84+
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	yes
GNU_CONFIGURE=		yes
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
MAXIMABINARY=	maxima_core
STRIP=	#strip(1) chokes on LISPBINARY
.elif defined(WITHOUT_CLISP) && defined(WITHOUT_CMUCL) && defined(WITH_GCL) && defined(WITHOUT_SBCL)
LISPSELECT=	--enable-gcl
LISPPORT=	gcl:${PORTSDIR}/lang/gcl
BINDIRECTORY=	binary-gcl
#LISPBINARY is null so fudge this so deinstall works cleanly
PLIST_SUB+=	LISPBINARY="@comment "
MAXIMABINARY=	maxima
.elif defined(WITHOUT_CLISP) && defined(WITHOUT_CMUCL) && defined(WITHOUT_GCL) && defined(WITH_SBCL)
.  if ${ARCH} == "i386"
DYNAMIC_SPACE_SIZE?=	512
.  else
DYNAMIC_SPACE_SIZE?=	1024
.  endif
.  if defined(DYNAMIC_SPACE_SIZE)
MAXIMA_LISP_OPTIONS+=	--dynamic-space-size ${DYNAMIC_SPACE_SIZE}
.  endif
.  if defined(MAXIMA_LISP_OPTIONS) && !empty(MAXIMA_LISP_OPTIONS)
LISPSELECT=	--with-sbcl="sbcl ${MAXIMA_LISP_OPTIONS}"
.  else
LISPSELECT=	--enable-sbcl
.  endif
LISPPORT=	sbcl:${PORTSDIR}/lang/sbcl
BINDIRECTORY=	binary-sbcl
#LISPBINARY is null so fudge this so deinstall works cleanly
PLIST_SUB+=	LISPBINARY="@comment "
MAXIMABINARY=	maxima_core
.else
IGNORE=		define only one lisp
.endif

post-patch:
	@${GREP} -Fe '.core' -l -r ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
	-e 's;\.core;_core;g'
	@${FIND} -X ${WRKSRC}/interfaces/xmaxima -name 'Makefile.in' | ${XARGS} \
	${REINPLACE_CMD} -e "s;tclsh;${TCLSH};g"
	@${REINPLACE_CMD} -e "s;/usr;${LOCALBASE};g" ${WRKSRC}/src/intl.lisp
	@cd ${WRKSRC}/doc/info ; ${LOCALBASE}/bin/bash ./fix_crlf ; \
	${LOCALBASE}/bin/bash ./fix_tab
	@${REINPLACE_CMD} -e 's;$$maxima_image_base;$${maxima_image_base};g' \
	${WRKSRC}/src/maxima.in
.if defined(MAXIMA_LISP_OPTIONS) && !empty(MAXIMA_LISP_OPTIONS)
	@${REINPLACE_CMD} -e 's;"@SBCL_NAME@";@SBCL_NAME@;g' \
	${WRKSRC}/src/maxima.in
.endif

pre-build:
	@${FIND} ${WRKSRC} \( -name '*.bak' -o -name '*.fbsd10bak' -o \
	-name '*.orig' \) -delete

post-install:
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

check test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} check

.include <bsd.port.post.mk>
