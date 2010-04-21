# New ports collection makefile for:	www/p5-Catalyst-Plugin-Unicode-Encoding
# Date created:				19 April 2010
# Whom:					Bill Brinzer <bill.brinzer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Unicode-Encoding
PORTVERSION=	0.9
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Unicode aware Catalyst

BUILD_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.8000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-libwww>=5.828:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.36:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	5.8.9+

MAN3=	Catalyst::Plugin::Unicode::Encoding.3

.include <bsd.port.mk>
