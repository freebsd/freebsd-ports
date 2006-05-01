# Ports collection makefile for:	p5-Catalyst-Plugin-Cache-Memcached
# Date created:				Dec 19, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Cache-Memcached
PORTVERSION=	0.5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Distributed cache for Catalyst

BUILD_DEPENDS=	p5-Catalyst>=0:${PORTSDIR}/www/p5-Catalyst \
		p5-Cache-Memcached>=0:${PORTSDIR}/databases/p5-Cache-Memcached
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Plugin::Cache::Memcached.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
