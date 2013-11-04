# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	player
PORTVERSION=	0.1.6
CATEGORIES=	multimedia
MASTER_SITES=	http://www.defora.org/os/download/download/4297/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Player-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop media player

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libSystem.so:${PORTSDIR}/devel/deforaos-libsystem \
		libDesktop.so:${PORTSDIR}/x11/deforaos-libdesktop
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

MAKE_ARGS+=	PREFIX=${PREFIX}
USE_GNOME=	gtk20
USES=		desktop-file-utils gettext pkgconfig

MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

post-install: compress-man

.include <bsd.port.mk>
