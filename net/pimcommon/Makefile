PORTNAME=	pimcommon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Common libraries for KDEPim
WWW=		https://invent.kde.org/pim/pimcommon

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	archive codecs colorscheme config contacts \
		coreaddons i18n itemmodels jobwidgets kcmutils \
		kio ktextaddons newstuff purpose service \
		widgetsaddons xmlgui \
		ecm:build
# KDEPIM components
USE_KDE+=	akonadi akonadicontacts akonadisearch imap \
		ldap libkdepim
# Plasma components
USE_KDE+=	activities
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
