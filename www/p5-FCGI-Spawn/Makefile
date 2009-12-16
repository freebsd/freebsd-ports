# New ports collection makefile for:	p5-FCGI-Spawn
# Date created:		2007-12-28
# Whom:			Peter <peter@vereshagin.org>
#
# $FreeBSD$
#

PORTNAME=	FCGI-Spawn
PORTVERSION=	0.15.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	peter@vereshagin.org
COMMENT=	Process manager/(CGI-like)application server for FastCGI protocol

RUN_DEPENDS=	${SITE_PERL}/FCGI/ProcManager.pm:${PORTSDIR}/www/p5-FCGI-ProcManager

PERL_CONFIGURE=	yes

MAN3=		FCGI::Spawn.3

.include <bsd.port.mk>
