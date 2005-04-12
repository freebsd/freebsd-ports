# New ports collection makefile for:	kf
# Date created:		Tue Oct 19 01:48:30 UTC 2004
# Whom:			Andrey Slusar <anray@inet.ua>
#
# $FreeBSD$
#

PORTNAME=	kf
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.habazie.rams.pl/kf/files/ \
		http://www.jabberstudio.org/projects/kf/releases/ \
		http://santinel.bas-net.by/files/

MAINTAINER=	anrays@gmail.com
COMMENT=	A simple Jabber client using the GTK+ 2.0 toolkit

LIB_DEPENDS=	loudmouth-1.0:${PORTSDIR}/net/loudmouth

USE_X_PREFIX=	yes
USE_GNOME=	libglade2
USE_GETOPT_LONG=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL_VER=	15

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.ifndef(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
CONFIGURE_ARGS+=	--enable-gtkspell
.endif

.include <bsd.port.mk>
