# New ports collection makefile for:	maxima
# Date created:				Jun 26 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$
#

PORTNAME=	maxima
PORTVERSION=	5.12.0
PORTREVISION=	0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	sf@slappy.org
COMMENT=	Symbolic mathematics program

BUILD_DEPENDS=	${LOCALBASE}/bin/${LISPPORT}
LIB_DEPENDS=	tk84:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	${LOCALBASE}/bin/${LISPPORT} \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19 autoconf:259
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--with-posix-shell=${LOCALBASE}/bin/bash \
			--with-wish=${LOCALBASE}/bin/wish8.4 \
			${LISPSELECT}
# don't pass "-s" to install to avoid trying to strip a shell script
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}"

MAN1=	maxima.1
INFO=	maxima xmaxima

PLIST_SUB=	BINDIR=${BINDIRECTORY}
PLIST_SUB+=	LISPBIN=${LISPBINARY}
PLIST_SUB+=	MAXIMABIN=${MAXIMABINARY}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAKE_ENV+=	CC="${CC}"
.endif

# Lisp to build with. Define only ONE of these!
#WITH_CLISP=	yes
#WITH_CMUCL=	yes
#WITH_GCL=	yes
WITH_SBCL=	yes

.if defined(WITH_CLISP)
LISPSELECT=	--enable-clisp
LISPPORT=	clisp:${PORTSDIR}/lang/clisp
BINDIRECTORY=	binary-clisp
LISPBINARY=	lisp.run
PLIST_SUB+=	LISPBINARY=""
MAXIMABINARY=	maxima.mem
.endif

.if defined(WITH_CMUCL)
LISPSELECT=	--enable-cmucl
LISPPORT=	lisp:${PORTSDIR}/lang/cmucl
BINDIRECTORY=	binary-cmucl
LISPBINARY=	lisp
PLIST_SUB+=	LISPBINARY=""
MAXIMABINARY=	maxima.core
.endif

.if defined(WITH_GCL)
LISPSELECT=	--enable-gcl
LISPPORT=	gcl:${PORTSDIR}/lang/gcl
BINDIRECTORY=	binary-gcl
#LISPBINARY is null so fudge this so deinstall works cleanly
PLIST_SUB+=	LISPBINARY="@comment "
MAXIMABINARY=	maxima
.endif

.if defined(WITH_SBCL)
LISPSELECT=	--enable-sbcl
LISPPORT=	sbcl:${PORTSDIR}/lang/sbcl
BINDIRECTORY=	binary-sbcl
#LISPBINARY is null so fudge this so deinstall works cleanly
PLIST_SUB+=	LISPBINARY="@comment "
MAXIMABINARY=	maxima.core
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "Maxima has the following tunable options:"
	@${ECHO} "  WITH_CLISP   Build with Clisp"
	@${ECHO} "  WITH_CMUCL   Build with CMU Common Lisp"
	@${ECHO} "  WITH_GCL     Build with GNU Common Lisp"
	@${ECHO} "  WITH_SBCL    Build with Steel Bank Common Lisp (default)"
	@${ECHO} ""

# rebuild older aclocal.m4
pre-configure:
	(cd ${WRKSRC} ; ${CP} -p aclocal.m4 aclocal.m4.orig ; ${ACLOCAL})
	(cd ${WRKSRC}/doc/info ; ${SH} fix_crlf ; ${SH} fix_tab)

.include <bsd.port.post.mk>
