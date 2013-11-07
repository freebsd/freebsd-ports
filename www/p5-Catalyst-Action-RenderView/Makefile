# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Action-RenderView
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sensible default end action for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.70:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Data-Visitor>=0.24:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-extract:
	@${REINPLACE_CMD} -i '' '/test_requires/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
