# $FreeBSD$

PORTNAME=	kitinerary
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	4
CATEGORIES=	net kde kde-applications

PATCH_SITES=	https://github.com/KDE/kitinerary/commit/
PATCHFILES=	7098c8be9a5e7fabf74543308bfaf11a2ebe5484.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Data Model and Extraction System for Travel Reservation information

LICENSE=	LGPL21

LIB_DEPENDS=	libpoppler.so:graphics/poppler \
		libZXing.so:textproc/zxing-cpp

USES=		compiler:c++11-lang cmake gettext gnome kde:5 pkgconfig qt:5 tar:xz
USE_GNOME=	libxml2
USE_KDE=	coreaddons ecm i18n
# Pim components
USE_KDE+=	calendarcore contacts kpkpass mime
USE_QT=		core declarative gui network \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
