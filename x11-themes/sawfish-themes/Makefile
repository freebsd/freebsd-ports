# New ports collection makefile for:	sawfish-themes
# Date created:				May 12 2004
# Whom:					Alexey Mikhailov <karma@ez.pereslavl.ru>
#
# $FreeBSD$
#

PORTNAME=	sawfish-themes
PORTVERSION=	0.11
CATEGORIES=	x11-themes
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/s/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	karma@ez.pereslavl.ru
COMMENT=	Themes for Sawfish window manager

RUN_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish2

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATA_DIRS=	2YearsToNever Anonymous Aquiline BWM Big Blackwindow Bubbles_Exact \
		CoolClean Derivative DoubleHeliX Elberg Empire FinalStep Greene2.0 Hacksaw \
		HeliX Klarth Microtene OrangeJuice SawLook SawthenaForever Strap \
		Studio T-16-blue T-16-red T-16-yellow Titanium V absolute-metal \
		bluefoo gorilla gorillaz mxflat typo

do-install:
	@${MKDIR} ${X11BASE}/share/sawfish/1.3/themes
.for d in ${DATA_DIRS}
	@${MKDIR} ${PREFIX}/share/sawfish/1.3/themes/${d}
	@cd ${WRKSRC}/${d} && ${FIND} . | \
		${CPIO} --quiet -pdm -L -R ${LIBOWN}:${LIBGRP} \
		${PREFIX}/share/sawfish/1.3/themes/${d}
.endfor

.include <bsd.port.mk>
