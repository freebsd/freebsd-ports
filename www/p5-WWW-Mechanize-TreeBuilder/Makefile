# Created by: Alex Deiter <Alex.Deiter@Gmail.COM>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-TreeBuilder
PORTVERSION=	1.20000
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	Combine WWW::Mechanize and HTML::TreeBuilder

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MooseX-Role-Parameterized>=0:devel/p5-MooseX-Role-Parameterized \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-Moose>=2.1200:devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Params-Util>0:devel/p5-Params-Util \
		p5-Test-WWW-Mechanize>0:devel/p5-Test-WWW-Mechanize

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
