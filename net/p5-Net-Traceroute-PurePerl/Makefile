# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	Net-Traceroute-PurePerl
PORTVERSION=	0.10
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Traceroute(1) functionality in perl via raw sockets

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-Traceroute>=0:${PORTSDIR}/net/p5-Net-Traceroute
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
