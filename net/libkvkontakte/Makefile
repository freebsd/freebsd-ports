# $FreeBSD$

PORTNAME=	libkvkontakte
PORTVERSION=	4.12.0
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/digikam

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for accessing vk.com

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libqjson.so:devel/qjson

USES=		cmake:outsource gettext pkgconfig tar:xz
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdelibs
USE_LDCONFIG=	yes

PLIST_SUB+=	SHLIB_VER="${PORTVERSION}"

.include <bsd.port.mk>
