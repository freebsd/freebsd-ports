# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Authentication
PORTVERSION=	0.10023
PORTREVISION=	2
PORTEPOCH=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Infrastructure plugin for the Catalyst authentication framework

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Plugin-Session>=0.10:www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Runtime>=0:www/p5-Catalyst-Runtime \
		p5-Class-Inspector>=0:devel/p5-Class-Inspector \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0:devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-String-RewritePrefix>=0:textproc/p5-String-RewritePrefix \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Catalyst-Plugin-Session>=0:www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-WWW-Mechanize-Catalyst>=0:devel/p5-Test-WWW-Mechanize-Catalyst

PORTSCOUT=	skipv:0.100091,0.100092

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
