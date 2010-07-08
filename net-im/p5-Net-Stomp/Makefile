# New ports collection makefile for:	Net-Stomp
# Date created:	   08 February 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-Stomp
PORTVERSION=	0.36
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Streaming Text Orientated Messaging Protocol Client

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::Stomp.3 Net::Stomp::Frame.3

.include <bsd.port.mk>
