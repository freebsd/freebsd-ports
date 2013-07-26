# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Component-ACCEPT_CONTEXT
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Make the Catalyst request context available in Models and Views

BUILD_DEPENDS=	p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Cycle>=0:${PORTSDIR}/devel/p5-Devel-Cycle

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Component::ACCEPT_CONTEXT.3

post-patch:
	${REINPLACE_CMD} -i '' -e '/auto_install/d' \
		-e '/Devel::Cycle/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
