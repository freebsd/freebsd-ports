PORTNAME=	kitinerary
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Data Model and Extraction System for Travel Reservation information
WWW=		https://www.kde.org/

LICENSE=	LGPL21

IGNORE_FreeBSD_13=	does not build with OpenSSL 1.1.1

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libphonenumber.so:devel/libphonenumber \
		libpoppler.so:graphics/poppler \
		libZXing.so:textproc/zxing-cpp

USES=		cmake gettext-tools gnome kde:6 pkgconfig qt:6 \
		shared-mime-info ssl tar:xz
USE_GNOME=	libxml2
# KDE Frameworks
USE_KDE=	calendarcore codecs contacts i18n mime \
		ecm:build
# KDE PIM
USE_KDE+=	kpkpass
USE_QT=		base declarative
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
