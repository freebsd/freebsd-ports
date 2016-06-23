# $FreeBSD$

PORTNAME=	kfilemetadata
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for extracting file metadata

LIB_DEPENDS=	libpoppler-qt4.so:graphics/poppler-qt4 \
		libtag.so:audio/taglib \
		libexiv2.so:graphics/exiv2 \
		libswscale.so:multimedia/ffmpeg \
		libepub.so:textproc/ebook-tools \
		libqmobipocket.so:graphics/kdegraphics4-mobipocket

USE_KDE4=	automoc4 kdelibs
USES=		cmake:outsource pkgconfig tar:xz
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
