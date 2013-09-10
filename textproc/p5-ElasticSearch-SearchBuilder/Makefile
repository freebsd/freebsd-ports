# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ElasticSearch-SearchBuilder
PORTVERSION=	0.18
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/../by-authors/id/D/DR/DRTECH/
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	ElasticSearch Query Builder

RUN_DEPENDS=	p5-Carp>=0:${PORTSDIR}/devel/p5-Carp \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
TEST_DEPENDS=	p5-Test-Deep>=:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump

USES=		perl5
USE_PERL5=	configure

MAN3=		ElasticSearch::SearchBuilder.3

.include <bsd.port.mk>
