# Created by: Scott Flatman <sf@dsinw.com>
# $FreeBSD$

PORTNAME=	maxima
PORTVERSION=	5.37.3
PORTREVISION=	1
CATEGORIES=	math lisp tk
MASTER_SITES=	SF/maxima/Maxima-source/${PORTVERSION}-source

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Symbolic mathematics program

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/${LISPPORT}
PATCH_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash
RUN_DEPENDS=	${LOCALBASE}/bin/${LISPPORT} \
		${LOCALBASE}/bin/gnuplot:math/gnuplot

USES=			gmake makeinfo perl5 python:build tk:84+
USE_PERL5=		build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--with-posix-shell=/bin/sh \
			--with-wish=${WISH} \
			${LISPSELECT}

INFO=	maxima imaxima xmaxima

PLIST_SUB=	BINDIR=${BINDIRECTORY}
PLIST_SUB+=	LISPBIN=${LISPBINARY}
PLIST_SUB+=	MAXIMABIN=${MAXIMABINARY}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_SINGLE=		LISP
OPTIONS_SINGLE_LISP=	CLISP CMUCL GCL SBCL

OPTIONS_DEFAULT=	SBCL

CLISP_DESC=	Build with Clisp
CMUCL_DESC=	Build with CMU Common Lisp
GCL_DESC=	Build with GNU Common Lisp
SBCL_DESC=	Build with Steel Bank Common Lisp

.include <bsd.port.pre.mk>

# Lisp to build with. Define only ONE of these!
.if ${PORT_OPTIONS:MCLISP}
LISPSELECT=	--enable-clisp
LISPPORT=	clisp:lang/clisp
BINDIRECTORY=	binary-clisp
LISPBINARY=	lisp.run
PLIST_SUB+=	LISPBINARY=""
MAXIMABINARY=	maxima.mem
.endif

.if ${PORT_OPTIONS:MCMUCL}
LISPSELECT=	--enable-cmucl
LISPPORT=	lisp:lang/cmucl
BINDIRECTORY=	binary-cmucl
LISPBINARY=	lisp
PLIST_SUB+=	LISPBINARY=""
MAXIMABINARY=	maxima_core
STRIP=	#strip(1) chokes on LISPBINARY
.endif

.if ${PORT_OPTIONS:MGCL}
LISPSELECT=	--enable-gcl
LISPPORT=	gcl:lang/gcl
BINDIRECTORY=	binary-gcl
#LISPBINARY is null so fudge this so deinstall works cleanly
PLIST_SUB+=	LISPBINARY="@comment "
MAXIMABINARY=	maxima
.endif

.if ${PORT_OPTIONS:MSBCL}
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
LISPPORT=	sbcl:lang/sbcl
BINDIRECTORY=	binary-sbcl
#LISPBINARY is null so fudge this so deinstall works cleanly
PLIST_SUB+=	LISPBINARY="@comment "
MAXIMABINARY=	maxima_core
.endif

post-patch:
	@${GREP} -Fe '.core' -l -r ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
	-e 's;\.core;_core;g'
	@${FIND} -X ${WRKSRC}/interfaces/xmaxima -name 'Makefile.in' | ${XARGS} \
	${REINPLACE_CMD} -e "s;tclsh;${TCLSH};g"
	@${REINPLACE_CMD} -e "s;/usr;${LOCALBASE};g" ${WRKSRC}/src/intl.lisp
	@${REINPLACE_CMD} -e 's;$$maxima_image_base;$${maxima_image_base};g' \
	${WRKSRC}/src/maxima.in
.if defined(MAXIMA_LISP_OPTIONS) && !empty(MAXIMA_LISP_OPTIONS)
	@${REINPLACE_CMD} -e 's;"@SBCL_NAME@";@SBCL_NAME@;g' \
	${WRKSRC}/src/maxima.in
	@${REINPLACE_CMD} -e 's;"$$(SBCL_NAME)";$$(SBCL_NAME);g' \
	${WRKSRC}/src/Makefile.in
.endif

pre-build:
	@${FIND} ${WRKSRC} \( -name '*.bak' -o -name '*.fbsd10bak' -o \
	-name '*.orig' \) -delete

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} \
	check

.include <bsd.port.post.mk>
