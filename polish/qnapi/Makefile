# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	qnapi
PORTVERSION=	0.1.8
CATEGORIES=	polish multimedia

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Qt5 based subtitle downloader

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BUILD_DEPENDS=	libmaia>0:${PORTSDIR}/net/libmaia
RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

USE_GITHUB=	yes

USES=		qmake
USE_QT5=	buildtools_build gui network widgets xml

CXXFLAGS+=	-I${LOCALBASE}/include/maia
QMAKE_ARGS=	LIBS=-lmaia

post-patch:
	@${REINPLACE_CMD} 's|/usr/share/icons/||g' \
		${WRKSRC}/doc/qnapi.desktop \
		${WRKSRC}/doc/qnapi-download.desktop \
		${WRKSRC}/doc/qnapi-scan.desktop

post-install:
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} qnapi-download.desktop \
		qnapi-scan.desktop ${STAGEDIR}${DESKTOPDIR})

.include <bsd.port.mk>
