# New ports collection makefile for:	www/p5-Catalyst-Plugin-Unicode-Encoding
# Date created:				19 April 2010
# Whom:					Bill Brinzer <bill.brinzer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Unicode-Encoding
PORTVERSION=	1.8
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Unicode aware Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.8000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>=1.36:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.837:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::Unicode::Encoding.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
