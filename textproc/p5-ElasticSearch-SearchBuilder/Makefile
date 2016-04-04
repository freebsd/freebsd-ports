# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ElasticSearch-SearchBuilder
PORTVERSION=	0.19
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/../by-authors/id/D/DR/DRTECH/
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	ElasticSearch Query Builder

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Carp>=0:devel/p5-Carp
TEST_DEPENDS=	p5-Test-Deep>=:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Data-Dump>=0:devel/p5-Data-Dump

DEPRECATED=	Use textproc/p5-Elasticsearch which is the official client
EXPIRATION_DATE=	2016-04-10

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
