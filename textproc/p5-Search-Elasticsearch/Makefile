PORTNAME=	Search-Elasticsearch
PORTVERSION=	8.12
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DRTECH
PKGNAMEPREFIX=	p5-

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	ElasticSearch API
WWW=		https://metacpan.org/release/Search-Elasticsearch

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Any-URI-Escape>=0:www/p5-Any-URI-Escape \
		p5-Data-Dumper>0:devel/p5-Data-Dumper \
		p5-Devel-GlobalDestruction>=0:devel/p5-Devel-GlobalDestruction \
		p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-HTTP-Tiny>=0.043:www/p5-HTTP-Tiny \
		p5-JSON-MaybeXS>=1.002002:converters/p5-JSON-MaybeXS \
		p5-libwww>0:www/p5-libwww \
		p5-Log-Any>=1.02:devel/p5-Log-Any \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=1.003:devel/p5-Moo \
		p5-namespace-clean>=0:devel/p5-namespace-clean \
		p5-Net-IP>0:net-mgmt/p5-Net-IP \
		p5-Package-Stash>=0:devel/p5-Package-Stash \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-URI>=0:net/p5-URI

TEST_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Log-Any>=1.02:devel/p5-Log-Any \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Pod>0:devel/p5-Test-Pod \
		p5-Test-SharedFork>0:devel/p5-Test-SharedFork

USES=		perl5

USE_PERL5=	configure

.include <bsd.port.mk>
