# $FreeBSD$

PORTNAME=	mpv-mpris
DISTVERSION=	0.3
CATEGORIES=	multimedia

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	MPRIS plugin for mpv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mpv:multimedia/mpv
RUN_DEPENDS=	mpv:multimedia/mpv

USES=		compiler:c11 gettext-runtime gnome pkgconfig
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
