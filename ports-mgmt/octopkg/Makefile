# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	octopkg
PORTVERSION=	0.2.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	ports-mgmt

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Graphical front-end to the FreeBSD pkg-ng package manager

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	aarnt

USE_QT5=	core concurrent gui network xml widgets quick concurrent \
		buildtools_build
USES=		qmake compiler:c++11-lib

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/octopi_green.png

DESKTOP_ENTRIES=	"OctoPkg" "A powerful pkgng front-end" \
			"${PREFIX}/share/pixmaps/octopi_green.png" \
			"${PORTNAME}" "System;" false

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/resources/images/octopi_green.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
