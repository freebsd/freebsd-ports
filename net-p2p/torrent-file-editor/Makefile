PORTNAME=	torrent-file-editor
PORTVERSION=	0.3.17
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI tool for creating and editing .torrent files
WWW=		https://torrent-file-editor.github.io/

LICENSE=	GPLv3+

USES=		cmake compiler:c++11-lang desktop-file-utils qt:5
USE_GITHUB=	yes
USE_QT=		buildtools:build linguisttools:build qmake:build \
		core gui widgets

CMAKE_ARGS=	-DQT5_BUILD:BOOL=ON \
		-DENABLE_PCH:BOOL=OFF

OPTIONS_DEFINE=	DONATION
OPTIONS_DEFAULT=	DONATION

DONATION_DESC=	Show donation text in the About dialog
DONATION_CMAKE_OFF=	-DDISABLE_DONATION:BOOL=ON

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,const auto file,const auto \&file,' \
		${WRKSRC}/bencodemodel.cpp ${WRKSRC}/mainwindow.cpp
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${REINPLACE_CMD} -i .c++20 '/file/s/version/&.txt/' \
		${WRKSRC}/cmake/Dmg.cmake ${WRKSRC}/cmake/Version.cmake

.include <bsd.port.post.mk>
