# New ports collection makefile for:	p5-FCGI-Async
# Date created:		2007-06-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	FCGI-Async
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	FCGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Module to allow use of FastCGI asynchronously

RUN_DEPENDS=	${SITE_PERL}/IO/Async/Buffer.pm:${PORTSDIR}/devel/p5-IO-Async

PERL_CONFIGURE=	yes

MAN3=		FCGI::Async.3 FCGI::Async::Constants.3 FCGI::Async::Request.3

.include <bsd.port.mk>
