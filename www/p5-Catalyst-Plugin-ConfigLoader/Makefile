# New ports collection makefile for:	www/p5-Catalyst-Plugin-ConfigLoader
# Date created:				July 11, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-ConfigLoader
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Load config files of various types

RUN_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Data-Visitor>=0.02:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-Config-Any>=0.04:${PORTSDIR}/devel/p5-Config-Any
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::ConfigLoader.3 \
	Catalyst::Plugin::ConfigLoader::Manual.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
