# $FreeBSD$

PORTNAME=	mpv-mpris
DISTVERSION=	0.2
CATEGORIES=	multimedia

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	MPRIS plugin for mpv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	mpv:multimedia/mpv

USES=		gettext-runtime gnome
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
