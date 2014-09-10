# $FreeBSD$

PORTNAME=	krename
PORTVERSION=	4.0.9
PORTREVISION=	8
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KDE4%20${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Powerful batch file renamer for KDE

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libpodofo.so:${PORTSDIR}/graphics/podofo

USES=		cmake:outsource tar:bzip2
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build

post-patch:
	${REINPLACE_CMD} 's,FREETYPE_INCLUDE_DIR,FREETYPE_INCLUDE_DIR_freetype2,' \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
