# New ports collection makefile for:	Catalyst-Plugin-ErrorCatcher
# Date created:				17 November 2010
# Whom:					andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-ErrorCatcher
PORTVERSION=	0.0.6.3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Catch application errors and emit them somewhere

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.71001:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Data-Accessor>=0:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		p5-IO>=0:${PORTSDIR}/devel/p5-IO \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-version>=0:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+
MAN3=		Catalyst::Plugin::ErrorCatcher.3 \
		Catalyst::Plugin::ErrorCatcher::Email.3 \
		Catalyst::Plugin::ErrorCatcher::File.3

.include <bsd.port.mk>
