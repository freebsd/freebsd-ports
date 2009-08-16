# New ports collection makefile for:	www/p5-Catalyst-Plugin-Session-Store-FastMmap
# Date created:				2 Jan 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-Store-FastMmap
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	FastMmap session storage backend

BUILD_DEPENDS=	p5-Cache-FastMmap>=1.13:${PORTSDIR}/devel/p5-Cache-FastMmap \
		p5-Catalyst-Plugin-Session>=0.09:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Session::Store::FastMmap.3

.include <bsd.port.mk>
