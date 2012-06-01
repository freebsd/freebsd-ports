# New ports collection makefile for:	tuntun
# Date created:		2008-09-16
# Whom:			Anderson S. Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	tuntun
PORTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	security gnome
MASTER_SITES=	http://tuntun.googlecode.com/files/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	A Gnome applet gui for OpenVPN

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	`pkg-config --cflags libgnomeui-2.0`
CONFIGURE_ARGS=	--libdir=${PREFIX}/libdata/servers
USE_GMAKE=	yes

USE_GNOME=	gnomehier intlhack gnomeprefix gnomehack gnomepanel glib20 \
		libgnomeui

.include <bsd.port.mk>
