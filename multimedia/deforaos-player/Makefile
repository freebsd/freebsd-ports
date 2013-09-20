# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	player
PORTVERSION=	0.1.4
CATEGORIES=	multimedia
MASTER_SITES=	http://www.defora.org/os/download/download/3708/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Player-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop media player

LICENSE=	GPLv3

LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

MAKE_ARGS+=	PREFIX=${PREFIX}
USE_GNOME=	gtk20 desktopfileutils
USES=		pkgconfig gettext

NO_STAGE=	yes
.include <bsd.port.mk>
