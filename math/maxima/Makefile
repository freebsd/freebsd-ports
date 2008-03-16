# New ports collection makefile for:	maxima
# Date created:				Jun 26 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$
#

PORTNAME=	maxima
PORTVERSION=	5.14.0
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
USE_AUTOTOOLS=	automake:19 autoconf:261
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

OPTIONS=	CLISP "Build with Clisp" off \
		CMUCL "Build with CMU Common Lisp" off \
		GCL "Build with GNU Common Lisp" off \
		SBCL "Build with Steel Bank Common Lisp" on

.include <bsd.port.pre.mk>

MAKE_ENV+=	CC="${CC}"

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

# rebuild older aclocal.m4
pre-configure:
	(cd ${WRKSRC} ; ${CP} -p aclocal.m4 aclocal.m4.orig ; ${ACLOCAL})
	(cd ${WRKSRC}/doc/info ; ${SH} fix_crlf ; ${SH} fix_tab)

.include <bsd.port.post.mk>
