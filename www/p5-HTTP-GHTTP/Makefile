# New ports collection makefile for:	HTTP::GHTTP
# Date created:		11 Jan 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	HTTP-GHTTP
PORTVERSION=	1.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl interface to the gnome ghttp library

LIB_DEPENDS=	ghttp.1:${PORTSDIR}/www/libghttp

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBS="-L${LOCALBASE}/lib -lghttp" INC="-I${LOCALBASE}/include"

MAN3=		HTTP::GHTTP.3

.include <bsd.port.mk>
