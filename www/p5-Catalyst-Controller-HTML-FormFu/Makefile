# Created by: Andrej Zverev <andrey.zverev@electro-com.ru>
# $FreeBSD$

PORTNAME=	Catalyst-Controller-HTML-FormFu
PORTVERSION=	2.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst FormFu Base Controller

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Component-InstancePerContext>=0:www/p5-Catalyst-Component-InstancePerContext \
		p5-Catalyst-Runtime>=5.71001:www/p5-Catalyst-Runtime \
		p5-Config-Any>=0:devel/p5-Config-Any \
		p5-HTML-FormFu>=2:www/p5-HTML-FormFu \
		p5-Moose>=1:devel/p5-Moose \
		p5-MooseX-Attribute-Chained>=1.0.1:devel/p5-MooseX-Attribute-Chained \
		p5-Regexp-Assemble>=0:devel/p5-Regexp-Assemble \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Catalyst-Action-RenderView>=0:www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Plugin-Session>=0:www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session-Store-File>=0:www/p5-Catalyst-Plugin-Session-Store-File \
		p5-Catalyst-View-TT>=0:www/p5-Catalyst-View-TT \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Test-Aggregate>=0.371:devel/p5-Test-Aggregate \
		p5-Test-WWW-Mechanize>=1.16:devel/p5-Test-WWW-Mechanize \
		p5-Test-WWW-Mechanize-Catalyst>=0:devel/p5-Test-WWW-Mechanize-Catalyst

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
