# $FreeBSD$

PORTNAME=	kde-thumbnailer-chm
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE thumbnail generator for CHM files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libchm.so:misc/chmlib

USES=		cmake kde:5 qt:5
USE_KDE=	ecm_build kio
USE_QT=		buildtools_build qmake_build gui

USE_GITHUB=	yes
GH_ACCOUNT=	Caig

PLIST_FILES=	${QT_PLUGINDIR_REL}/chmthumbnail.so \
		share/kservices5/chmthumbnail.desktop

.include <bsd.port.mk>
