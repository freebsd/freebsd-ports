# $FreeBSD$

PORTNAME=	kdenetwork-strigi-analyzers
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	11
CATEGORIES=	net kde kde-kde4
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi analyzers for network-related file formats

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs strigi automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
