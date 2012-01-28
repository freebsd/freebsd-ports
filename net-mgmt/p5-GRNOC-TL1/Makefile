# New ports collection makefile for:	p5-GRNOC-TL1
# Date created:				03 12 2011
# Whom:					Muhammad Moinur Rahman <5u623l20@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	GRNOC-TL1
PORTVERSION=	1.2.2
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	SF/routerproxy/${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Module supports retrieval of data from different models of TL1 devices

PERL_CONFIGURE=	yes

BUILD_DEPENDS+=	${SITE_PERL}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet
RUN_DEPENDS+=	${BUILD_DEPENDS}

.include <bsd.port.mk>
