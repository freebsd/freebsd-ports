# New ports collection makefile for:	p5-HTTP-Tiny
# Date created:		2011-03-04
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Tiny
PORTVERSION=	0.016
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A small, simple, correct HTTP/1.1 client

OPTIONS=	HTTPS	"https support" on

PERL_CONFIGURE=	yes

MAN3=		HTTP::Tiny.3

.include <bsd.port.options.mk>

.if !defined(WITHOUT_HTTPS)
RUN_DEPENDS+=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.include <bsd.port.mk>
