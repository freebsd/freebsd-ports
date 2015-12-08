# Created by: mikael.urankar@gmail.com
# $FreeBSD$

PORTNAME=	omxplayer
PORTVERSION=	20151109
CATEGORIES=	multimedia

MAINTAINER=	mikael.urankar@gmail.com
COMMENT=	Raspberry Pi video player

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libEGL.so:${PORTSDIR}/misc/raspberrypi-userland \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/share/fonts/freefont-ttf/FreeSans.ttf:${PORTSDIR}/x11-fonts/freefont-ttf

ONLY_FOR_ARCHS=	armv6

CFLAGS+=	-Dfopen64=fopen -Dfseeko64=fseeko -Dftello64=ftello
ALL_TARGET=	omxplayer.bin

USE_GITHUB=	yes
GH_ACCOUNT=	popcornmix
GH_TAGNAME=	6f073c9

USES=		gmake shebangfix
USE_GCC=	yes
SHEBANG_FILES=	omxplayer

PLIST_FILES=	bin/omxplayer bin/omxplayer.bin
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|LOCALBASE|${LOCALBASE}|g' ${WRKSRC}/omxplayer.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omxplayer.bin ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/omxplayer ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
