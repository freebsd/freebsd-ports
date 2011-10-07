# New ports collection makefile for:	p5-FCGI-Async
# Date created:		2007-06-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	FCGI-Async
PORTVERSION=	0.22
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module to allow use of FastCGI asynchronously

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-IO-Async>=0:${PORTSDIR}/devel/p5-IO-Async \
  		p5-Net-FastCGI>=0:${PORTSDIR}/www/p5-Net-FastCGI

PERL_CONFIGURE=	yes

MAN3=		Plack::Handler::FCGI::Async.3 \
		FCGI::Async::PSGI.3 \
		FCGI::Async.3

.include <bsd.port.mk>
