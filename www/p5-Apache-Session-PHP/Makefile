# New ports collection makefile for:	p5-Apache-Session-PHP
# Date created:				16 April 2003
# Whom:	      				Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-Session-PHP
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Glue Apache::Session with PHP::Session

BUILD_DEPENDS=	${SITE_PERL}/PHP/Session.pm:${PORTSDIR}/www/p5-PHP-Session \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session 
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::Session::PHP.3 Apache::Session::Serialize::PHP.3 Apache::Session::Store::PHP.3

.include <bsd.port.mk>
