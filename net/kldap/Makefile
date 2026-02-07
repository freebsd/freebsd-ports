PORTNAME=	kldap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LDAP access API for KDE
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++11-lib gettext kde:6 ldap qt:6 tar:xz
USE_KDE=	completion config coreaddons i18n kio service widgetsaddons \
		ecm:build
# pim components
USE_KDE+=	mbox
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
