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
COMMENT=	Compute the golden string

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	goldstr.1

.if !exists(/usr/include/getopt.h)
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgnugetopt
.endif

.include <bsd.port.mk>
