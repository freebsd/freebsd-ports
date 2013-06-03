# Created by: Mitsuru Y <mitsuruy@reallyenglish.com>
# $FreeBSD$

PORTNAME=	ElasticSearch
PORTVERSION=	0.65
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DRTECH
PKGNAMEPREFIX=	p5-

MAINTAINER=	mitsuruy@reallyenglish.com
COMMENT=	An API for communicating with ElasticSearch

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-URI-Escape>=0:${PORTSDIR}/www/p5-Any-URI-Escape \
		p5-ElasticSearch-SearchBuilder>=0:${PORTSDIR}/textproc/p5-ElasticSearch-SearchBuilder \
		p5-HTTP-Lite>=0:${PORTSDIR}/www/p5-HTTP-Lite \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	YES

MAN3=		ElasticSearch::Transport::HTTPTiny.3 \
		ElasticSearch::ScrolledSearch.3 \
		ElasticSearch::Transport.3 \
		ElasticSearch::Transport::HTTP.3 \
		ElasticSearch::Transport::HTTPLite.3 \
		ElasticSearch.3 \
		ElasticSearch::Error.3 \
		ElasticSearch::QueryParser.3 \
		ElasticSearch::Util.3 \
		ElasticSearch::TestServer.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
