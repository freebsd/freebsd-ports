# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kqoauth
PORTVERSION=	0.98
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of OAuth 1.0 in C++ for Qt

LICENSE=	LGPL21

USES=		pkgconfig qmake
USE_QT4=	corelib network gui moc_build qtestlib_build
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
QMAKE_SOURCE_PATH=	${PORTNAME}.pro

USE_GITHUB=	yes
GH_ACCOUNT=	kypeli
GH_PROJECT=	kQOAuth

pre-configure:
	${REINPLACE_CMD} -e 's|$${target.path}/pkgconfig|$${INSTALL_PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
