# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

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

.include <bsd.port.mk>
