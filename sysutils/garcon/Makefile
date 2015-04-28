# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	garcon
PORTVERSION=	0.4.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Freedesktop compliant menu library

# garcon's source code is licensed under GPLv2, while its
# documentation is under GFDL 1.1.
LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=	gmake libtool pathfix pkgconfig gettext-tools xfce tar:bzip2
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	libmenu

CONFIGURE_ARGS=--without-html-dir

OPTIONS_DEFINE=		NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

.include <bsd.port.mk>
