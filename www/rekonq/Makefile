# New ports collection makefile for:	rekonq
# Date created:		2009-08-11
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rekonq
PORTVERSION=	0.4.0
CATEGORIES=	www kde
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A lightweight KDE browser based on WebKit

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs automoc4 kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
