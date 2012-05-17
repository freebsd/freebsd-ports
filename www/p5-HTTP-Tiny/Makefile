# New ports collection makefile for:	p5-HTTP-Tiny
# Date created:		2011-03-04
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Tiny
PORTVERSION=	0.021
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A small, simple, correct HTTP/1.1 client

OPTIONS=	HTTPS	"https support" on

PERL_CONFIGURE=	yes

MAN3=		HTTP::Tiny.3

.include <bsd.port.options.mk>

.if !defined(WITHOUT_HTTPS)
BUILD_DEPENDS+=	p5-IO-Socket-SSL>=1.56:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Mozilla-CA>=0:${PORTSDIR}/www/p5-Mozilla-CA
RUN_DEPENDS+=	p5-IO-Socket-SSL>=1.56:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Mozilla-CA>=0:${PORTSDIR}/www/p5-Mozilla-CA
.endif

.include <bsd.port.mk>
