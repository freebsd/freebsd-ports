# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Component-ACCEPT_CONTEXT
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Make the Catalyst request context available in Models and Views

BUILD_DEPENDS=	p5-Catalyst-Runtime>0:www/p5-Catalyst-Runtime
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Cycle>=0:devel/p5-Devel-Cycle

USES=		perl5
USE_PERL5=	configure

post-patch:
	${REINPLACE_CMD} -i '' -e '/auto_install/d' \
		-e '/Devel::Cycle/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
