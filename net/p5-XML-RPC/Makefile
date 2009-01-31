# New ports collection makefile for:	p5-XML-RPC
# Date created:	   05 Dec 2008
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RPC
PORTVERSION=	0.9
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Pure Perl implementation for an XML-RPC client and server

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/TreePP.pm:${PORTSDIR}/textproc/p5-XML-TreePP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::RPC.3

.include <bsd.port.mk>
