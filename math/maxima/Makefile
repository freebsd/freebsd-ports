# New ports collection makefile for:	maxima
# Date created:				Jun 26 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$
#

PORTNAME=	maxima
PORTVERSION=	5.9.1
PORTREVISION=	0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	sf@slappy.org
COMMENT=	Symbolic mathematics program

BUILD_DEPENDS=	${LISPPORT}
LIB_DEPENDS=	tk84:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	${LOCALBASE}/bin/${LISPPORT} \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2

USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	253
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--with-posix-shell=${LOCALBASE}/bin/bash \
			--with-wish=${LOCALBASE}/bin/wish8.4 \
			${LISPSELECT}
# don't pass "-s" to install to avoid trying to strip a shell script
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}"

MAN1=		maxima.1
INFO=		maxima

PLIST_SUB=	BINDIR=${BINDIRECTORY}
PLIST_SUB+=	LISPBIN=${LISPBINARY}
PLIST_SUB+=	MAXIMABIN=${MAXIMABINARY}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

# Lisp to build with. Define only ONE of these!
WITH_CMUCL=	yes
#WITH_SBCL=	yes
#WITH_GCL=	yes
#WITH_CLISP=	yes

.if defined(WITH_CMUCL)
LISPSELECT=	--enable-cmucl
LISPPORT=	lisp:${PORTSDIR}/lang/cmucl
BINDIRECTORY=	binary-cmucl
LISPBINARY=	lisp
MAXIMABINARY=	maxima.core
.endif

.if defined(WITH_GCL)
LISPSELECT=	--enable-gcl
LISPPORT=	gcl:${PORTSDIR}/lang/gcl
# check these when unbroken
BINDIRECTORY=	binary-gcl
LISPBINARY=	lisp
MAXIMABINARY=	maxima
BROKEN=		"Broken at LISP:USE-PACKAGE."
.endif

.if defined(WITH_CLISP)
LISPSELECT=	--enable-clisp
LISPPORT=	clisp:${PORTSDIR}/lang/clisp
BINDIRECTORY=	binary-clisp
LISPBINARY=	lisp.run
MAXIMABINARY=	maxima.mem
.if ${OSVERSION} >= 600000
BROKEN=		"Dumps core while compiling bessel.fas in CURRENT"
.endif
.endif

.if defined(WITH_SBCL)
LISPSELECT=	--enable-sbcl
LISPPORT=	sbcl:${PORTSDIR}/lang/sbcl
# check these when unbroken
BINDIRECTORY=	binary-sbcl
LISPBINARY=	lisp
MAXIMABINARY=	maxima.core
BROKEN=		"Drops into debugger when loading xerprn.fasl"
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "Maxima has the following tunable options:"
	@${ECHO} "  WITH_CMUCL   Build with CMU Common Lisp (default)"
	@${ECHO} "  WITH_GCL     Build with GNU Common Lisp"
	@${ECHO} "  WITH_CLISP   Build with Clisp"
	@${ECHO} "  WITH_SBCL    Build with Steel Bank Common Lisp"
	@${ECHO} ""

post-extract:
		@${RM} -f ${WRKSRC}/doc/info/*.info*

.include <bsd.port.post.mk>
