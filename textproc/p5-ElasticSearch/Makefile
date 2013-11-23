# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ElasticSearch
PORTVERSION=	0.65
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/../by-authors/id/D/DR/DRTECH/
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	ElasticSearch API

BUILD_DEPENDS:=	p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS:=	p5-ElasticSearch-SearchBuilder>=0:${PORTSDIR}/textproc/p5-ElasticSearch-SearchBuilder \
		p5-Carp>=0:${PORTSDIR}/devel/p5-Carp \
		p5-Any-URI-Escape>=0:${PORTSDIR}/www/p5-Any-URI-Escape \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Encode>=0:${PORTSDIR}/converters/p5-Encode \
		p5-Exporter>=0:${PORTSDIR}/devel/p5-Exporter \
		p5-File-Path>=0:${PORTSDIR}/devel/p5-File-Path \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp \
		p5-HTTP-Lite>=0:${PORTSDIR}/www/p5-HTTP-Lite \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-HTTP-Tiny>=0:${PORTSDIR}/www/p5-HTTP-Tiny \
		p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-constant>=0:${PORTSDIR}/devel/p5-constant \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent
TEST_DEPENDS=	p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

MAN3=		ElasticSearch.3 \
		ElasticSearch::Error.3 \
		ElasticSearch::QueryParser.3 \
		ElasticSearch::ScrolledSearch.3 \
		ElasticSearch::TestServer.3 \
		ElasticSearch::Transport.3 \
		ElasticSearch::Transport::HTTP.3 \
		ElasticSearch::Transport::HTTPLite.3 \
		ElasticSearch::Transport::HTTPTiny.3 \
		ElasticSearch::Util.3

NO_STAGE=	yes
.include <bsd.port.mk>
