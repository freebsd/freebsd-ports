# New ports collection makefile for:	Net-ManageSieve
# Date created:	   11 Aug 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-ManageSieve
PORTVERSION=	0.10
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	ManageSieve Protocol Client

RUN_DEPENDS=	${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL

PERL_CONFIGURE=	YES

MAN3=		Net::ManageSieve.3

.include <bsd.port.mk>
