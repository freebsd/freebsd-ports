# ex:ts=8
# Ports collection makefile for:	CGI::Cookie::Splitter
# Date created:			Nov 29, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	CGI-Cookie-Splitter
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Split big cookies into smaller ones

BUILD_DEPENDS=	p5-CGI-Simple>=0:${PORTSDIR}/www/p5-CGI-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	CGI::Cookie::Splitter.3

.include <bsd.port.mk>
