# $FreeBSD$

PORTNAME=	libksieve
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sieve libriares for KDEPim

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libsasl2.so:security/cyrus-sasl2

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons ecm i18n iconthemes jobwidgets kio newstuff service \
		sonnet syntaxhighlighting wallet widgetsaddons windowsystem xmlgui
# pim components
USE_KDE+=	akonadi identitymanagement libkdepim mailtransport mime \
		pimcommon pimtextedit
USE_QT=		concurrent core dbus declarative gui location network printsupport testlib \
		uitools webchannel webengine widgets xml \
                buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
