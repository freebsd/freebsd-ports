PORTNAME=	mpv-mpris
DISTVERSION=	1.2
CATEGORIES=	multimedia

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	MPRIS plugin for mpv
WWW=		https://github.com/hoyon/mpv-mpris

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mpv:multimedia/mpv
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
RUN_DEPENDS=	mpv:multimedia/mpv

USES=		compiler:c11 gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	hoyon
USE_GNOME=	glib20

ALL_TARGET=	mpris.so

PLIST_FILES=	etc/mpv/scripts/mpris.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mpv/scripts
	${INSTALL_LIB} ${BUILD_WRKSRC}/mpris.so \
			${STAGEDIR}${PREFIX}/etc/mpv/scripts

.include <bsd.port.mk>
