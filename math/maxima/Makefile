# New ports collection makefile for:	maxima
# Date created:				Jun 26 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$
#

PORTNAME=	maxima
PORTVERSION=	5.9.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}

MAINTAINER=	sf@slappy.org
COMMENT=	Symbolic mathematics program

BUILD_DEPENDS=	${LISPPORT}
LIB_DEPENDS=	tk84:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	${LOCALBASE}/bin/${LISPPORT} \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2

USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--with-posix-shell=${LOCALBASE}/bin/bash \
			--with-wish=${LOCALBASE}/bin/wish8.4 \
			${LISPSELECT}
# don't pass "-s" to install to avoid trying to strip a shell script
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}"

MAN1=		maxima.1
INFO=		maxima

PLIST_SUB=	LISPBIN=${LISPBINARY}

#Only define ONE of these!
USE_CMUCL=	yes
#USE_GCL=	yes
#USE_CLISP=	yes

.if defined(USE_CMUCL)
LISPSELECT=	--enable-cmucl
LISPPORT=	lisp:${PORTSDIR}/lang/cmucl
LISPBINARY=	binary-cmucl/maxima.core
.endif

.if defined(USE_GCL)
LISPSELECT=	--enable-gcl
LISPPORT=	gcl:${PORTSDIR}/lang/gcl
LISPBINARY=	binary-gcl/maxima
.endif

.if defined(USE_CLISP)
LISPSELECT=	--enable-clisp
LISPPORT=	clisp:${PORTSDIR}/lang/clisp
# The value for LISPBINARY is a guess. Fix when the core dump is sorted out.
LISPBINARY=	binary-clisp/maxima.core
BROKEN=		"Dumps core while compiling bessel.fas in CURRENT"
.endif

post-extract:
		@${RM} -f ${WRKSRC}/doc/info/*.info*

.include <bsd.port.mk>
