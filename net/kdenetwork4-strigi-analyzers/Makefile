# $FreeBSD$

PORTNAME=	kdenetwork-strigi-analyzers
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	net kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi analyzers for network-related file formats

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs strigi automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
