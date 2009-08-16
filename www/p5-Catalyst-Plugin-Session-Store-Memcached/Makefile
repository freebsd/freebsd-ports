# New ports collection makefile for:	www/p5-Catalyst-Plugin-Session-Store-Memcached
# Date created:				2 Jan 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-Store-Memcached
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Memcached storage backend for session data

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Cache-Memcached-Managed>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Managed \
		p5-Catalyst-Plugin-Session>=0.01:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.2+

MAN3=	Catalyst::Plugin::Session::Store::Memcached.3

.include <bsd.port.mk>
