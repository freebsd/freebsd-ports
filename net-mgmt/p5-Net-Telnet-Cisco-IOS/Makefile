# New ports collection makefile for:	p5-Net-Telnet-Cisco-IOS
# Date created:		2008-02-07
# Whom:			Tsung-Han Yeh <snowfly@yunteche.du.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Telnet-Cisco-IOS
PORTVERSION=	0.6
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}beta

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Manage Cisco IOS Devices

RUN_DEPENDS=	${SITE_PERL}/Net/Telnet/Cisco.pm:${PORTSDIR}/net-mgmt/p5-Telnet-Cisco
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Telnet::Cisco::IOS.3

.include <bsd.port.mk>
