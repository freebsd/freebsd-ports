# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CatalystX-SimpleLogin
PORTVERSION=	0.18
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide a simple Login controller which can be reused

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Action-REST>=0.74:${PORTSDIR}/www/p5-Catalyst-Action-REST \
		p5-Catalyst-Action-RenderView>=0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-ActionRole-ACL>=0:${PORTSDIR}/www/p5-Catalyst-ActionRole-ACL \
		p5-Catalyst-Plugin-Authentication>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-State-Cookie>=0.17:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session-Store-File>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-File \
		p5-Catalyst-Runtime>=5.80:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-View-TT>=0:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-CatalystX-Component-Traits>=0.13:${PORTSDIR}/www/p5-CatalystX-Component-Traits \
		p5-CatalystX-InjectComponent>=0:${PORTSDIR}/www/p5-CatalystX-InjectComponent \
		p5-HTML-FormHandler>=0.28001:${PORTSDIR}/www/p5-HTML-FormHandler \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Moose-Autobox>=0:${PORTSDIR}/devel/p5-Moose-Autobox \
		p5-MooseX-MethodAttributes>=0.18:${PORTSDIR}/devel/p5-MooseX-MethodAttributes \
		p5-MooseX-RelatedClassRoles>=0:${PORTSDIR}/devel/p5-MooseX-RelatedClassRoles \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Common>=0:${PORTSDIR}/devel/p5-MooseX-Types-Common \
		p5-SQL-Translator>=0:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
