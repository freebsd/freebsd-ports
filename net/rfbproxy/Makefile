# ex:ts=8
# Ports collection makefile for:	rfbproxy
# Date created:			Sep 5, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	rfbproxy
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://cyberelk.net/tim/data/rfbproxy/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple tool for recording VNC sessions

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=		rfbproxy.1
PLIST_FILES=	bin/rfbproxy

.include <bsd.port.mk>
