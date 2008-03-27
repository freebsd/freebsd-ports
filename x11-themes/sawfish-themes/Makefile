# New ports collection makefile for:	sawfish-themes
# Date created:				May 12 2004
# Whom:					Alexey Mikhailov <karma@ez.pereslavl.ru>
#
# $FreeBSD$
#

PORTNAME=	sawfish-themes
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/s/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	anray@FreeBSD.org
COMMENT=	Themes for Sawfish window manager

RUN_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATA_DIRS=	2YearsToNever Anonymous Aquiline BWM Big Blackwindow Bubbles_Exact \
		CoolClean Derivative DoubleHeliX Elberg Empire FinalStep Greene2.0 Hacksaw \
		HeliX Klarth Microtene OrangeJuice SawLook SawthenaForever Strap \
		Studio T-16-blue T-16-red T-16-yellow Titanium V absolute-metal \
		bluefoo gorilla gorillaz mxflat typo

do-install:
	@${MKDIR} ${PREFIX}/share/sawfish/themes
.for d in ${DATA_DIRS}
	@${MKDIR} ${PREFIX}/share/sawfish/themes/${d}
	@cd ${WRKSRC}/${d} && ${FIND} . | \
		${CPIO} --quiet -pdm -L -R ${LIBOWN}:${LIBGRP} \
		${PREFIX}/share/sawfish/themes/${d}
.endfor

.include <bsd.port.mk>
