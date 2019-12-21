# $FreeBSD$

PORTNAME=	qtkeychain
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	security

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Platform independent Qt API for storing passwords

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig qt:5
USE_GITHUB=	yes
USE_QT=		core dbus linguisttools_build buildtools_build qmake_build
GH_ACCOUNT=	frankosterfeld
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

CONFLICTS_INSTALL=	qtkeychain-qt[45]

OPTIONS_DEFINE=		LIBSECRET
OPTIONS_DEFAULT=	LIBSECRET

LIBSECRET_DESC=		Enable libsecret backend

LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_BOOL=	LIBSECRET_SUPPORT

.include <bsd.port.mk>
