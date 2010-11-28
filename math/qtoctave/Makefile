# New ports collection makefile for:	qtoctave
# Date created:		2009-02-18
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qtoctave
PORTVERSION=	0.9.1
CATEGORIES=	math
MASTER_SITES=	http://forja.rediris.es/frs/download.php/1760/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt4 frontend for Octave

RUN_DEPENDS=	octave:${PORTSDIR}/math/octave

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	designer gui network script svg xml \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
CMAKE_ARGS+=	-DWITH_UseRPMTools:Bool=Off
CMAKE_USE_PTHREAD=	yes

.include <bsd.port.mk>
