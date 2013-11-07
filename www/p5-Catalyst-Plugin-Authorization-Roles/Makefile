# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Authorization-Roles
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Role based authorization for Catalyst

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-Authentication>=0.10003:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Set-Object>=1.14:${PORTSDIR}/devel/p5-Set-Object \
		p5-UNIVERSAL-isa>=0.05:${PORTSDIR}/devel/p5-UNIVERSAL-isa
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

post-extract:
	@${REINPLACE_CMD} -e '/^test_requires/d' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
