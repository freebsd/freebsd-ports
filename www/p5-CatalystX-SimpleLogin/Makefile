# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CatalystX-SimpleLogin
PORTVERSION=	0.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide a simple Login controller which can be reused

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Action-REST>=0.74:www/p5-Catalyst-Action-REST \
		p5-Catalyst-Plugin-Authentication>=0:www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Plugin-Session>=0.35:www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Runtime>=5.80013:www/p5-Catalyst-Runtime \
		p5-Catalyst-View-TT>=0:www/p5-Catalyst-View-TT \
		p5-CatalystX-Component-Traits>=0.13:www/p5-CatalystX-Component-Traits \
		p5-CatalystX-InjectComponent>=0:www/p5-CatalystX-InjectComponent \
		p5-HTML-FormHandler>=0.28001:www/p5-HTML-FormHandler \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-MethodAttributes>=0.18:devel/p5-MooseX-MethodAttributes \
		p5-MooseX-RelatedClassRoles>=0.004:devel/p5-MooseX-RelatedClassRoles \
		p5-MooseX-Types-Common>=0:devel/p5-MooseX-Types-Common \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-Try-Tiny>=0.24:lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Catalyst-Action-RenderView>=0:www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-ActionRole-ACL>=0:www/p5-Catalyst-ActionRole-ACL \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Class-Load>=0.20:devel/p5-Class-Load \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-SQL-Translator>=0:databases/p5-SQL-Translator \
		p5-Test-Exception>=0:devel/p5-Test-Exception

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
