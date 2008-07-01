# ex:ts=8
# Ports collection makefile for:	HTML::Encoding
# Date created:			Jun 5, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	HTML-Encoding
PORTVERSION=	0.60
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Determine the encoding of HTML/XML/XHTML documents

RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	5.8.0+

MAN3=	HTML::Encoding.3

.include <bsd.port.mk>
