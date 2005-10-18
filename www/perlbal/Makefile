# New ports collection makefile for:	p5-Danga-Socket
# Date created:		2005-08-08
# Whom:			Jacques Marneweck <jacques@php.net>
#
# $FreeBSD$
#

PORTNAME=	Perlbal
PORTVERSION=	1.36
CATEGORIES=	www
MASTER_SITES=	http://www.danga.com/dist/Perlbal/
PKGNAMEPREFIX=	p5-

MAINTAINER=	jacques@php.net
COMMENT=	Reverse-proxy load balancer and webserver

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/BSD/Resource.pm:${PORTSDIR}/devel/p5-BSD-Resource \
		p5-Danga-Socket>=1.44:${PORTSDIR}/devel/p5-Danga-Socket \
		${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	perlbal.1
MAN3=	Perlbal.3

.include <bsd.port.mk>
