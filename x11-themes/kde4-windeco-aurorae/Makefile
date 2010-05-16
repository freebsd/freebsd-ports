# New ports collection makefile for:   crystal
# Date created:                        Mon Oct 5 2009
# Whom:                                Mina R Waheeb
#
# $FreeBSD$
#

PORTNAME=	aurorae
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde-windeco-
DISTNAME=	107158-${PORTNAME}-${PORTVERSION}

MAINTAINER=	syncer@gmail.com
COMMENT=	Theme engine for KWin window decorations

USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

IGNORE=		is obsolete: Aurorae shipped with KDE SC since version 4.4
DEPRECATED=	${IGNORE}
EXPIRATION_DATE=2010-08-16

.include <bsd.port.mk>
