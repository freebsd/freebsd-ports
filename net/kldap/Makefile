PORTNAME=	kldap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LDAP access API for KDE
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake gettext-tools kde:6 ldap qt:6 tar:xz
# KDE Frameworks
USE_KDE=	i18n kio widgetsaddons \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
