# $FreeBSD$

PORTNAME=	kfilemetadata
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	20
CATEGORIES=	sysutils kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for extracting file metadata

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libtag.so:audio/taglib \
		libexiv2.so:graphics/exiv2 \
		libswscale.so:multimedia/ffmpeg \
		libepub.so:textproc/ebook-tools \
		libqmobipocket.so:graphics/kdegraphics-mobipocket-kde4

USES=		cmake:outsource kde:4 pkgconfig qt:4 tar:xz
USE_KDE=	automoc4 kdelibs
USE_QT=		corelib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
