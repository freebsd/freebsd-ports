# New ports collection makefile for:	ortp
# Date created:				20 October 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ortp
PORTVERSION=	0.8.1
CATEGORIES=	net
MASTER_SITES=	http://www.linphone.org/ortp/sources/

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A Real-time Transport Protocol (RTP) stack

USE_GNOME=	glib20 pkgconfig gnomehack
USE_AUTOTOOLS=	libtool:13:inc
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
