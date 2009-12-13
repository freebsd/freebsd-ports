# New ports collection makefile for:	Authen-Simple-HTTP
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple-HTTP
PORTVERSION=	0.2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple HTTP authentication

BUILD_DEPENDS=	${SITE_PERL}/Authen/Simple.pm:${PORTSDIR}/security/p5-Authen-Simple \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

MAN3=	Authen::Simple::HTTP.3

PERL_MODBUILD=	5.8.0+

.include <bsd.port.mk>
