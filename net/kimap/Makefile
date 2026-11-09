PORTNAME=	kimap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE API for IMAP support
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	coreaddons i18n kio mime \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
