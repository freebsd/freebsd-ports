# Ports collection makefile for:	p5-Catalyst-Plugin-PageCache
# Date created:				Dec 19, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-PageCache
PORTVERSION=	0.31
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cache the output of entire pages

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-MRO-Compat>=0.10:${PORTSDIR}/devel/p5-MRO-Compat

PERL_CONFIGURE=	5.8.1+

MAN3=		Catalyst::Plugin::PageCache.3

.include <bsd.port.mk>
