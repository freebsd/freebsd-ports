# New ports collection makefile for:	tuntun
# Date created:		2008-09-16
# Whom:			Anderson S. Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	tuntun
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	http://tuntun.googlecode.com/files/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	A Gnome applet gui for OpenVPN

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`pkg-config --cflags libgnomeui-2.0`" \
		LIBS="`pkg-config --libs libgnomeui-2.0`"
CONFIGURE_ARGS=	--libdir=${PREFIX}/libdata/servers
USE_GMAKE=	yes

USE_GNOME=	gnomehier intlhack gnomeprefix gnomehack gnomepanel glib20

.include <bsd.port.mk>
