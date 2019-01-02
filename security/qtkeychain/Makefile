# $FreeBSD$

PORTNAME=	qtkeychain
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	security
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Platform independent Qt API for storing passwords

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	frankosterfeld
USE_LDCONFIG=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

.  if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		qt:4
CMAKE_ON=	BUILD_WITH_QT4
USE_QT=		corelib dbus linguisttools_build moc_build rcc_build qmake_build
PLIST_SUB+=	PLIST_QT_PREFIX_UPCASE=Qt PLIST_QT_PREFIX=qt
PLIST=		${PKGDIR}/pkg-plist.${FLAVOR}
.  else
USES+=		compiler:c++11-lang qt:5
USE_QT=		core dbus linguisttools_build buildtools_build qmake_build
PLIST_SUB+=	PLIST_QT_PREFIX_UPCASE=Qt5 PLIST_QT_PREFIX=qt5
PLIST=		${PKGDIR}/pkg-plist.${FLAVOR}
.  endif

OPTIONS_DEFINE=		LIBSECRET
OPTIONS_DEFAULT=	LIBSECRET

LIBSECRET_DESC=		Enable libsecret backend

LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_BOOL=	LIBSECRET_SUPPORT

.include <bsd.port.mk>
