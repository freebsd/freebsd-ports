# New ports collection makefile for:	rekonq
# Date created:		2009-08-11
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rekonq
DISTVERSION=	0.9.2
CATEGORIES=	www kde
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION:R}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Lightweight KDE browser based on WebKit

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	script webkit \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
