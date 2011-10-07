# New ports collection makefile for:	p5-Catalyst-Controller-HTML-FormFu
# Date created:		2007-12-24
# Whom:			Andrej Zverev <andrey.zverev@electro-com.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Controller-HTML-FormFu
PORTVERSION=	0.09003
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst FormFu Base Controller

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Action-RenderView>=0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Plugin-ConfigLoader>=0.23:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session-Store-File>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-File \
		p5-Catalyst-View-TT>=0:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	p5-Catalyst-Component-InstancePerContext>=0:${PORTSDIR}/www/p5-Catalyst-Component-InstancePerContext \
		p5-Catalyst-Runtime>=5.71001:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-HTML-FormFu>=0.09:${PORTSDIR}/www/p5-HTML-FormFu \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-ChainedAccessors>=0.02:${PORTSDIR}/devel/p5-MooseX-ChainedAccessors \
		p5-Regexp-Assemble>=0:${PORTSDIR}/devel/p5-Regexp-Assemble \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-WWW-Mechanize>=1.16:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		p5-Test-WWW-Mechanize-Catalyst>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Controller::HTML::FormFu.3 \
		Catalyst::Helper::HTML::FormFu.3 \
		HTML::FormFu::Element::RequestToken.3

.include <bsd.port.mk>
