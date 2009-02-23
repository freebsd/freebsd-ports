# New ports collection makefile for:	POE-Component-Client-SMTP
# Date created:	   24 May 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-SMTP
PORTVERSION=	0.21
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	SMTP client POE component

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Filter/Transparent/SMTP.pm:${PORTSDIR}/mail/p5-POE-Filter-Transparent-SMTP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=		POE::Component::Client::SMTP.3

.include <bsd.port.mk>
