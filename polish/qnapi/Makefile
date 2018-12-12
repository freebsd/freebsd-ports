# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	qnapi
PORTVERSION=	0.2.3
PORTREVISION=	5
CATEGORIES=	polish multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt5 based subtitle downloader

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BUILD_DEPENDS=	qt-maybe>0:devel/qt-maybe \
		libmaia>0:net/libmaia
LIB_DEPENDS=	libmediainfo.so:multimedia/libmediainfo \
		libzen.so:multimedia/libzen
RUN_DEPENDS=	7z:archivers/p7zip

USE_GITHUB=	yes

USES=		compiler:c++11-lib pkgconfig qmake qt:5
USE_GL=		gl
USE_QT=		buildtools_build core gui network widgets xml

CXXFLAGS+=	-I${LOCALBASE}/include/maia

post-patch:
	@${REINPLACE_CMD} 's|/usr|${PREFIX}|; s|share/man|man|' \
		${WRKSRC}/qnapi.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qnapi
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} qnapi-download.desktop \
		qnapi-scan.desktop ${STAGEDIR}${DESKTOPDIR})

.include <bsd.port.mk>
