# New ports collection makefile for:	wmapm
# Date created:		99/07/02
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmapm
PORTVERSION= 	3.01
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	taoka@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/${DISTNAME}/wmapm
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes

BINMODE=	2755
BINGRP=		operator

pre-build:
	cd ${WRKDIR}/${DISTNAME}/wmapm; ${GMAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmapm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmapm.1 ${PREFIX}/man/man1

MAN1=		wmapm.1

.include <bsd.port.mk>
