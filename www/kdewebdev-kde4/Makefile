# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdewebdev
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	12
CATEGORIES=	www kde kde-kde4
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Comprehensive html/website development environment

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libtidy.so:www/tidy-lib \
		libboost_thread.so:devel/boost-libs

USES=		cmake kde:4 qt:4 tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	kdelibs pimlibs automoc4
USE_QT=		dbus porting_build \
		qmake_build moc_build rcc_build uic_build uic3_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
