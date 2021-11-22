PORTNAME=	qtkeychain
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.2
CATEGORIES=	security

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Platform independent Qt API for storing passwords

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig qt:5
USE_GITHUB=	yes
USE_QT=		core dbus buildtools_build qmake_build
GH_ACCOUNT=	frankosterfeld
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=		LIBSECRET NLS
OPTIONS_DEFAULT=	LIBSECRET NLS

LIBSECRET_DESC=		Enable libsecret backend
LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_BOOL=	LIBSECRET_SUPPORT

NLS_USE=		qt=linguisttools_build
NLS_CMAKE_BOOL=		BUILD_TRANSLATIONS

.include <bsd.port.mk>
