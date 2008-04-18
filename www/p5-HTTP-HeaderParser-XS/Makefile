# New ports collection makefile for:	HTTP-HeaderParser-XS
# Date created:	   18 Apr 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	HTTP-HeaderParser-XS
PORTVERSION=	0.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	XS extension for processing HTTP headers

PERL_CONFIGURE=	5.8.1+

MAKE_ARGS+=	CC=${CXX} LD=${CXX}

MAN3=		HTTP::HeaderParser::XS.3

.include <bsd.port.mk>
