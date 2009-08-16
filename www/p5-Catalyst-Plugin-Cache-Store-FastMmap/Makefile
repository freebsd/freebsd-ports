# Ports collection makefile for: p5-Catalyst-Plugin-Cache-Store-FastMmap
# Date created:			 Apr 5, 2007
# Whom:				 lbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Cache-Store-FastMmap
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	FastMmap cache store for Catalyst::Plugin::Cache

BUILD_DEPENDS=	p5-Cache-FastMmap>=0:${PORTSDIR}/devel/p5-Cache-FastMmap \
		p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-Cache>=0.01:${PORTSDIR}/www/p5-Catalyst-Plugin-Cache \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

DEPRECATED=	Refer to the documentation for details on how to reconfigure your Catalyst application to avoid this module

MAN3=	Catalyst::Plugin::Cache::Backend::FastMmap.3 \
	Catalyst::Plugin::Cache::Store::FastMmap.3

.include <bsd.port.mk>
