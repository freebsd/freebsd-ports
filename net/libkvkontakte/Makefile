PORTNAME=	libkvkontakte
DISTVERSION=	5.0.0
PORTREVISION=	7
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/digikam

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for accessing vk.com
WWW=		https://www.digikam.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

DEPRECATED=Depends on deprecated www/qt5-webkit
EXPIRATION_DATE=2023-11-26

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons i18n kdewebkit kio service widgetsaddons \
		ecm:build
USE_QT=		concurrent core dbus gui network webkit widgets \
		buildtools:build qmake:build

.include <bsd.port.mk>
