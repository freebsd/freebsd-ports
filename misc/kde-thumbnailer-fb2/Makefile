# $FreeBSD$

PORTNAME=	kde-thumbnailer-fb2
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	160180-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE thumbnail generator for fb2 files

USES=		cmake:outsource kde:4
USE_KDE=	kdelibs automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	lib/kde4/fb2thumbnail.so \
		share/kde4/services/fb2thumbnail.desktop

.include <bsd.port.mk>
