# $FreeBSD$

PORTNAME=	knemo
PORTVERSION=	0.7.6
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	12956-${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE network monitor

USE_BZIP2=	yes
USES=		cmake
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_KDE4=	kdeprefix kdelibs workspace automoc4

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
