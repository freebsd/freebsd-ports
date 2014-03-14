# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-Entities-Interpolate
PORTVERSION=	1.05
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Call HTML::Entities::encode_entities, via a hash, within a string

LICENSE=	ART20

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Tie-Function>=0:${PORTSDIR}/devel/p5-Tie-Function
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.45:${PORTSDIR}/devel/p5-Test-Pod

USE_PERL5=	configure
USES=		perl5 tar:tgz

.include <bsd.port.mk>
