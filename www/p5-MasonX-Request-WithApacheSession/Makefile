# New ports collection makefile for:	p5-MasonX-Request-WithApacheSession
# Date created:			2003.07.21
# Whom:				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	MasonX-Request-WithApacheSession
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An interface to Apache::Session for HTML::Mason

BUILD_DEPENDS=	${SITE_PERL}/HTML/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/Apache/Session/Wrapper.pm:${PORTSDIR}/www/p5-Apache-Session-Wrapper
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		MasonX::Request::WithApacheSession.3 \
		MasonX::Request::WithMultiSession.3

.include <bsd.port.mk>
