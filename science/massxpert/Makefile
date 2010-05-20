# New ports collection makefile for:	massxpert
# Date created:		2010-05-14
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	massxpert
PORTVERSION=	2.3.6
CATEGORIES=	science
MASTER_SITES=	http://download.tuxfamily.org/massxpert/source/

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	The massXpert software for (bio)chemists

USE_QT_VER=	4
USE_CMAKE=	yes
USE_LDCONFIG=	yes
QT_COMPONENTS=	gui xml rcc_build qmake_build uic_build moc_build \
		svg

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
CMAKE_USE_PTHREAD=	yes
.endif

.include <bsd.port.post.mk>
