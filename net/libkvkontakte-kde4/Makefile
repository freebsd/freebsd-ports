# $FreeBSD$

PORTNAME=	libkvkontakte
PORTVERSION=	4.12.0
PORTREVISION=	4
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
PKGNAMESUFFIX=	-kde4
DIST_SUBDIR=	KDE/digikam

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for accessing vk.com

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libqjson.so:devel/qjson@qt4

USES=		cmake gettext kde:4 pkgconfig qt:4 tar:xz
USE_QT=		moc_build qmake_build rcc_build uic_build
USE_KDE=	automoc4 kdelibs
USE_LDCONFIG=	yes

PLIST_SUB+=	SHLIB_VER="${PORTVERSION}"

.include <bsd.port.mk>
