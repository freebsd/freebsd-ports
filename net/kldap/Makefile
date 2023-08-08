PORTNAME=	kldap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LDAP access API for KDE
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libqt5keychain.so:security/qtkeychain@qt5

USES=		cmake compiler:c++11-lib gettext kde:5 ldap qt:5 tar:xz
USE_KDE=	completion config coreaddons i18n kio widgetsaddons service \
		ecm:build
# pim components
USE_KDE+=	mbox
USE_QT=		concurrent core dbus gui network widgets \
		buildtools:build qmake:build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
