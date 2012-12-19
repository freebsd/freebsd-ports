# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	player
PORTVERSION=	0.1.4
CATEGORIES=	multimedia
MASTER_SITES=	http://www.defora.org/os/download/download/3708/
DISTNAME=	Player-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop media player

LICENSE=	GPLv3

LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes

.include <bsd.port.mk>
