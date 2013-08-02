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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Traceroute(1) functionality in perl via raw sockets

BUILD_DEPENDS=	p5-Net-Traceroute>=0:${PORTSDIR}/net/p5-Net-Traceroute
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::Traceroute::PurePerl.3

.include <bsd.port.mk>
