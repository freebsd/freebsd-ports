# ex:ts=8
# Ports collection makefile for:	rfbproxy
# Date created:			Sep 5, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	rfbproxy
PORTVERSION=	0.6.5
CATEGORIES=	net
MASTER_SITES=	http://cyberelk.net/tim/data/rfbproxy/stable/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A simple tool for recording VNC sessions

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=	rfbproxy.1

.include <bsd.port.mk>
