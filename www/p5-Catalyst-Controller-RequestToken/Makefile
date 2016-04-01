# Created by: Bill Brinzer <bill.brinzer@gmail.com>
# $FreeBSD$

PORTNAME=	Catalyst-Controller-RequestToken
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Generate and validate unique tokens across HTTP requests (anti-CSRF)

BUILD_DEPENDS=	p5-Catalyst-Action-RenderView>=0:www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session>=0:www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Runtime>=5.7000:www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
