# New ports collection makefile for:	maxima
# Date created:				Jun 26 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$
#

PORTNAME=	maxima
PORTVERSION=	5.9.0
CATEGORIES=	math
MASTER_SITES=	http://unc.dl.sourceforge.net/sourceforge/maxima/ \
		http://aleron.dl.sourceforge.net/sourceforge/maxima/ \
		http://switch.dl.sourceforge.net/sourceforge/maxima/ \
		http://heanet.dl.sourceforge.net/sourceforge/maxima/ \
		http://umn.dl.sourceforge.net/sourceforge/maxima/ \
		http://flow.dl.sourceforge.net/sourceforge/maxima/ \
		http://belnet.dl.sourceforge.net/sourceforge/maxima/ \
		http://easynews.dl.sourceforge.net/sourceforge/maxima/ \
		http://twtelecom.dl.sourceforge.net/sourceforge/maxima/ \
		http://cesnet.dl.sourceforge.net/sourceforge/maxima/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	sf@slappy.org
COMMENT=	Maxima symbolic computation program

BUILD_DEPENDS=	lisp:${PORTSDIR}/lang/cmucl
LIB_DEPENDS=	tk84:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	${LOCALBASE}/bin/lisp:${PORTSDIR}/lang/cmucl \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2

USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--with-posix-shell=${PREFIX}/bin/bash
# don't pass "-s" to install to avoid trying to strip a shell script
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}"

MAN1=		maxima.1

.include <bsd.port.mk>
