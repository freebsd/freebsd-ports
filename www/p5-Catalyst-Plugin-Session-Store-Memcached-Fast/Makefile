# New ports collection makefile for:	www/p5-Catalyst-Plugin-Session-Store-Memcached-Fast
# Date created:				11 Dec 2008
# Whom:					Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-Store-Memcached-Fast
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Memcached storage backend for session data

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Cache-Memcached-Fast>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Fast \
		p5-Catalyst-Plugin-Session>=0.01:${PORTSDIR}/www/p5-Catalyst-Plugin-Session
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.2+

MAN3=	Catalyst::Plugin::Session::Store::Memcached::Fast.3

.include <bsd.port.mk>
