# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session
PORTVERSION=	0.40
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic Catalyst Session plugin

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Do not add p5-Catalyst-Plugin-Session-State-Cookie to TEST_DEPENDS to avoid cyclic dependency
BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.71001:www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Moose>=0.76:devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0.00801:devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-Object-Signature>=0:devel/p5-Object-Signature \
		p5-namespace-clean>=0.10:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-WWW-Mechanize-PSGI>=0:devel/p5-Test-WWW-Mechanize-PSGI

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/^is_upgrading_needed/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
