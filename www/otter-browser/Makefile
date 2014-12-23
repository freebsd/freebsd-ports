# $FreeBSD$

PORTNAME=	otter
PORTVERSION=	0.9.03
CATEGORIES=	www
# Avoid pkgname conflict with misc/otter
PKGNAMESUFFIX=	-browser
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Browser based on Qt 5

USE_QT5=	concurrent core gui network printsupport qmake_build script \
		sql webkit widgets buildtools_build
USES=		cmake:outsource desktop-file-utils

USE_GITHUB=	yes
GH_ACCOUNT=	Emdek
GH_PROJECT=	otter
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	cc6c9a7

PLIST_FILES=	bin/otter-browser \
		share/applications/otter-browser.desktop

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/otter-browser \
		${STAGEDIR}/${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/otter-browser.desktop \
		${STAGEDIR}/${DESKTOPDIR}

.include <bsd.port.mk>
