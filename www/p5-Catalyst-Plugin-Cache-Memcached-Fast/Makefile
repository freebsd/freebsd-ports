# New ports collection makefile for:	p5-Catalyst-Plugin-Cache-Memcached-Fast
# Date created:	   10 Oct 2008
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Cache-Memcached-Fast
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Catalyst Plugin for Cache::Memcached::Fast

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Cache/Memcached/Fast.pm:${PORTSDIR}/databases/p5-Cache-Memcached-Fast \
		${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::Cache::Memcached::Fast.3

WRKSRC=	${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
