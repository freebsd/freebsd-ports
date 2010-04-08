# New ports collection makefile for:	p5-Net-Traceroute-PurePerl
# Date created:				April 01 2010
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-Traceroute-PurePerl
PORTVERSION=	0.10
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	Traceroute(1) functionality in perl via raw sockets

BUILD_DEPENDS=	${SITE_PERL}/Net/Traceroute.pm:${PORTSDIR}/net/p5-Net-Traceroute
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Net::Traceroute::PurePerl.3

.include <bsd.port.mk>
