# New ports collection makefile for:	www/p5-Catalyst-Plugin-ConfigLoader
# Date created:				July 11, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-ConfigLoader
PORTVERSION=	0.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Load config files of various types

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7008:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Data-Visitor>=0.24:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-Config-Any>=0.08:${PORTSDIR}/devel/p5-Config-Any \
		p5-MRO-Compat>=0.09:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Catalyst::Plugin::ConfigLoader.3 \
	Catalyst::Plugin::ConfigLoader::Manual.3

.include <bsd.port.mk>
