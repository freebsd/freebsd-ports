# New ports collection makefile for:	qtoctave
# Date created:		2009-02-18
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qtoctave
PORTVERSION=	0.8.2
CATEGORIES=	math
MASTER_SITES=	http://forja.rediris.es/frs/download.php/1383/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt4 frontend for Octave

RUN_DEPENDS=	octave:${PORTSDIR}/math/octave

USE_QT_VER=	4
QT_COMPONENTS=	gui svg xml qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
CMAKE_ARGS+=	-DWITH_UseRPMTools:Bool=Off
CMAKE_USE_PTHREAD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}

.include <bsd.port.mk>
