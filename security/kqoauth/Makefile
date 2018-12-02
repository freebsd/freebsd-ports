# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kqoauth
PORTVERSION=	0.98
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of OAuth 1.0 in C++ for Qt

LICENSE=	LGPL21

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		pkgconfig qmake qt:4
USE_QT=		corelib network gui moc_build qtestlib_build
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
