# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ElasticSearch
PORTVERSION=	0.66
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/../by-authors/id/D/DR/DRTECH/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-legacy

MAINTAINER=	tj@FreeBSD.org
COMMENT=	ElasticSearch API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-ElasticSearch-SearchBuilder>=0:textproc/p5-ElasticSearch-SearchBuilder \
		p5-Any-URI-Escape>=0:www/p5-Any-URI-Escape \
		p5-PathTools>=0:devel/p5-PathTools \
		p5-HTTP-Lite>=0:www/p5-HTTP-Lite \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-HTTP-Tiny>=0:www/p5-HTTP-Tiny \
		p5-IO-Compress>=0:archivers/p5-IO-Compress \
		p5-JSON>=0:converters/p5-JSON \
		p5-libwww>=0:www/p5-libwww \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken \
		p5-URI>=0:net/p5-URI \
		p5-YAML>=0:textproc/p5-YAML
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception

DEPRECATED=	Use textproc/p5-Elasticsearch which is the official client
EXPIRATION_DATE=	2016-04-10

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
