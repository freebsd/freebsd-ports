# ex:ts=8
# New ports collection makefile for:	goldstr
# Date created:			Jul 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	goldstr
PORTVERSION=	1.6.0
CATEGORIES=	misc
MASTER_SITES=	http://it.geocities.com/andreamolteni/prog/goldstr/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Compute the golden string

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=	goldstr.1

.include <bsd.port.mk>
