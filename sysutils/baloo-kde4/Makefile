# $FreeBSD$

PORTNAME=	baloo
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	9
CATEGORIES=	sysutils kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE framework for searching and managing user metadata

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

CONFLICTS_INSTALL=	kde-runtime-4.12.* \
			kf5-baloo-5.*

LIB_DEPENDS=	libxapian.so:databases/xapian-core \
		libqjson.so:devel/qjson@qt4

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	akonadi automoc4 kdelibs kfilemetadata \
		pimlibs
USE_QT=		corelib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
