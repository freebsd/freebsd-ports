# New ports collection makefile for:	www/p5-Catalyst-Plugin-Session-Store-Memcached
# Date created:				2 Jan 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-Store-Memcached
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Memcached storage backend for session data

BUILD_DEPENDS=	p5-Catalyst>=5.0:${PORTSDIR}/www/p5-Catalyst \
		p5-Cache-Memcached-Managed>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Managed \
		p5-Catalyst-Plugin-Session>=0.01:${PORTSDIR}/www/p5-Catalyst-Plugin-Session
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Plugin::Session::Store::Memcached.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500801
IGNORE=	requires Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
