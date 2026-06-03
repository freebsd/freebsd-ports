PORTNAME=	mpv-mpris
DISTVERSION=	1.1
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPRIS plugin for mpv
WWW=		https://github.com/hoyon/mpv-mpris

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mpv:multimedia/mpv
RUN_DEPENDS=	mpv:multimedia/mpv

USES=		compiler:c11 gettext-runtime gmake gnome pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	hoyon

ALL_TARGET=	mpris.so

PLIST_FILES=	etc/mpv/scripts/mpris.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mpv/scripts
	${INSTALL_LIB} ${BUILD_WRKSRC}/mpris.so \
			${STAGEDIR}${PREFIX}/etc/mpv/scripts

.include <bsd.port.mk>
