# New ports collection makefile for:	HTTP::GHTTP
# Date created:		11 Jan 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	HTTP-GHTTP
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

LIB_DEPENDS=	ghttp.1:${PORTSDIR}/www/libghttp

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	LIBS="-L${LOCALBASE}/lib" INC="-I${LOCALBASE}/include"

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTTP::GHTTP.3

.include <bsd.port.mk>
