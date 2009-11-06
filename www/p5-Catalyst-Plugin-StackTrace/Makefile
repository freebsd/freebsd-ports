# New ports collection makefile for:	www/p5-Catalyst-Plugin-StackTrace
# Date created:				Jan 11 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-StackTrace
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Display a stack trace on the debug screen

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-MRO-Compat>=0.10:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::StackTrace.3

.include <bsd.port.mk>
