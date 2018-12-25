# $FreeBSD$

PORTNAME=	kde-thumbnailer-epub
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
PKGNAMESUFFIX=	-kde4
DISTNAME=	151210-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE thumbnail generator for ePub files

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

PORTSCOUT=	limit:^1\.0

USES=		cmake kde:4 qt:4
USE_KDE=	kdelibs automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	lib/kde4/epubthumbnail.so \
		share/kde4/services/epubthumbnail.desktop

.include <bsd.port.mk>
