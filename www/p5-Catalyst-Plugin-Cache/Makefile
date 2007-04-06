# Ports collection makefile for:	p5-Catalyst-Plugin-Cache
# Date created:			Apr 5, 2007
# Whom:				lbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Cache
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Flexible caching support for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::Cache.3 \
	Catalyst::Plugin::Cache::Backend.3 \
	Catalyst::Plugin::Cache::Backend::Memory.3 \
	Catalyst::Plugin::Cache::Choose::KeyRegexes.3 \
	Catalyst::Plugin::Cache::Curried.3 \
	Catalyst::Plugin::Cache::Store.3 \
	Catalyst::Plugin::Cache::Store::Memory.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
