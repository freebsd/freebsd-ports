# $FreeBSD$

PORTNAME=	qtkeychain
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	security
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	6yearold@gmail.com
COMMENT=	Platform independent Qt API for storing passwords

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt4 qt5
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	frankosterfeld
USE_LDCONFIG=	yes
USE_KDE=	ecm
PLIST_SUB+=	VERSION=${PORTVERSION}

.  if ${FLAVOR} == qt4
CMAKE_ON=	BUILD_WITH_QT4
USE_QT4=	corelib dbus linguisttools_build moc_build rcc_build qmake_build
PLIST_SUB+=	PLIST_QT_PREFIX_UPCASE=Qt PLIST_QT_PREFIX=qt
PLIST=		${PKGDIR}/pkg-plist.${FLAVOR}
.  else
USE_QT5=	core dbus linguisttools_build buildtools_build qmake_build
PLIST_SUB+=	PLIST_QT_PREFIX_UPCASE=Qt5 PLIST_QT_PREFIX=qt5
PLIST=		${PKGDIR}/pkg-plist.${FLAVOR}
.  endif


.include <bsd.port.mk>
