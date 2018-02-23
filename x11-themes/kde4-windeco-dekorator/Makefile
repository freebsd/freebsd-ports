# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	dekorator
PORTVERSION=	0.5.1
PORTREVISION=	8
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde4-windeco-
DISTNAME=	87921-${PORTNAME}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Transparent KDE4 window decoration

LICENSE=	GPLv2

LIB_DEPENDS=	libqimageblitz.so:x11/qimageblitz

USES=		cmake kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4 workspace
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
