# $FreeBSD$

PORTNAME=	kde-thumbnailer-epub
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.9b
CATEGORIES=	misc kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE thumbnail generator for ePub files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake kde:5 qt:5
USE_KDE=	archive ecm_build kio
USE_QT=		buildtools_build qmake_build gui xmlpatterns

USE_GITHUB=	yes
GH_ACCOUNT=	Caig

PLIST_FILES=	${QT_PLUGINDIR_REL}/epubthumbnail.so \
		share/kservices5/epubthumbnail.desktop

.include <bsd.port.mk>
