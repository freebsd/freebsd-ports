# $FreeBSD$

PORTNAME=	qtkeychain
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMESUFFIX?=	-qt5

MAINTAINER=	6yearold@gmail.com
COMMENT=	Platform independent Qt API for storing passwords

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	frankosterfeld

USES=		cmake
USE_LDCONFIG=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-qt4"
CONFLICTS_INSTALL=	qtkeychain-qt5-[0-9]*
CMAKE_ARGS+=	-DBUILD_WITH_QT4=YES
USE_QT4=	corelib dbus linguisttools_build moc_build rcc_build qmake_build
PLIST=		${PKGDIR}/pkg-plist.qt4
PLIST_SUB+=	PLIST_QT_PREFIX_UPCASE=Qt PLIST_QT_PREFIX=qt
.else
CONFLICTS_INSTALL=	qtkeychain-qt4-[0-9]*
USE_QT5=	core dbus linguisttools_build buildtools_build qmake_build
PLIST=		${PKGDIR}/pkg-plist.qt5
PLIST_SUB+=	PLIST_QT_PREFIX_UPCASE=Qt5 PLIST_QT_PREFIX=qt5
.endif

.include <bsd.port.mk>
