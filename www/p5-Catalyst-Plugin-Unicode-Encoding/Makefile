# Created by: Bill Brinzer <bill.brinzer@gmail.com>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Unicode-Encoding
PORTVERSION=	1.9
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Unicode aware Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

DEPRECATED=	This module now part of core Catalyst distribution
EXPIRATION_DATE=	2013-09-04

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.90015:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Encode>=2.49:${PORTSDIR}/converters/p5-Encode \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>=1.36:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.837:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::Unicode::Encoding.3

.include <bsd.port.mk>
