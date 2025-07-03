PORTNAME=	kitinerary
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Data Model and Extraction System for Travel Reservation information
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libphonenumber.so:devel/libphonenumber \
		libpoppler.so:graphics/poppler \
		libZXing.so:textproc/zxing-cpp

USES=		cmake compiler:c++11-lang gettext gnome kde:6 pkgconfig qt:6 \
		shared-mime-info ssl tar:xz
USE_GNOME=	libxml2
USE_KDE=	archive codecs coreaddons i18n \
		ecm:build
# Pim components
USE_KDE+=	calendarcore contacts kpkpass mime
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
