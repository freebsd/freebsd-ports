# Ports collection makefile for:	p5-Catalyst-Plugin-Cache
# Date created:			Apr 5, 2007
# Whom:				lbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Cache
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible caching support for Catalyst

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Cache.3 \
	Catalyst::Plugin::Cache::Backend.3 \
	Catalyst::Plugin::Cache::Backend::Memory.3 \
	Catalyst::Plugin::Cache::Choose::KeyRegexes.3 \
	Catalyst::Plugin::Cache::Curried.3 \
	Catalyst::Plugin::Cache::Store.3 \
	Catalyst::Plugin::Cache::Store::Memory.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,ok|Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
