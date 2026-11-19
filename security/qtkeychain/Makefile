PORTNAME=	qtkeychain
DISTVERSION=	0.18.0
CATEGORIES=	security

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Platform independent Qt API for storing passwords
WWW=		https://github.com/frankosterfeld/qtkeychain

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig qt:6
CMAKE_ARGS=	-DBUILD_WITH_QT5=OFF \
		-DQT_MKSPECDIR_REL=${QT_MKSPECDIR_REL}
USE_GITHUB=	yes
USE_QT=		base
GH_ACCOUNT=	frankosterfeld
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
PLIST_SUB=	VERSION=${PORTVERSION} \
		QT_VER=6

OPTIONS_DEFINE=		LIBSECRET NLS
OPTIONS_DEFAULT=	LIBSECRET NLS

LIBSECRET_DESC=		Enable libsecret backend
LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_BOOL=	LIBSECRET_SUPPORT

NLS_USE=		qt=tools:build
NLS_CMAKE_BOOL=		BUILD_TRANSLATIONS

.include <bsd.port.mk>
