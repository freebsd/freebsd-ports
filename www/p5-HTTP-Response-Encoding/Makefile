# New ports collection makefile for:	p5-HTTP-Response-Encoding
# Date created:		2007-10-27
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Response-Encoding
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Adds encoding() to HTTP::Response

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	5.8.1+

MAN3=		HTTP::Response::Encoding.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS+=	p5-Encode>=2:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
