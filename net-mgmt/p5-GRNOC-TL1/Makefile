# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	GRNOC-TL1
PORTVERSION=	1.3.10
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	SF/routerproxy/${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Retrieve data from different models of TL1 devices

BUILD_DEPENDS=	p5-Date-Calc>0:devel/p5-Date-Calc \
		p5-Net-SSH-Expect>0:net/p5-Net-SSH-Expect \
		p5-Net-Telnet>0:net/p5-Net-Telnet
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
