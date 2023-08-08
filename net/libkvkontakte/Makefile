PORTNAME=	libkvkontakte
DISTVERSION=	5.0.0
PORTREVISION=	6
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/digikam

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for accessing vk.com
WWW=		https://www.digikam.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons ecm i18n kdewebkit kio service widgetsaddons
USE_QT=		concurrent core dbus gui network webkit widgets \
		buildtools:build qmake:build

.include <bsd.port.mk>
