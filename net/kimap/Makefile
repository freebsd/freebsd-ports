PORTNAME=	kimap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE API for IMAP support
WWW=		https://www.kde.org/

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	codecs config coreaddons i18n kio service \
		ecm:build
# pim components
USE_KDE+=	mime
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
