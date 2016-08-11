# $FreeBSD$

PORTNAME=	baloo
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE framework for searching and managing user metadata

CONFLICTS_INSTALL=	kde-runtime-4.12.*

LIB_DEPENDS=	libxapian.so:databases/xapian-core \
		libqjson.so:devel/qjson

USE_KDE4=	akonadi automoc4 kdelibs kfilemetadata \
		pimlibs

USES=		cmake:outsource gmake tar:xz
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
