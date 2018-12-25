# $FreeBSD$

PORTNAME=	kde-thumbnailer-fb2
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE thumbnail generator for fb2 files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake kde:5 qt:5
USE_KDE=	archive ecm_build kio
USE_QT=		buildtools_build qmake_build gui

USE_GITHUB=	yes
GH_ACCOUNT=	Caig

PLIST_FILES=	${QT_PLUGINDIR_REL}/fb2thumbnail.so \
		share/kservices5/fb2thumbnail.desktop

.include <bsd.port.mk>
