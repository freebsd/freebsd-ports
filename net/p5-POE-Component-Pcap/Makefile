# New ports collection makefile for:	POE-Component-Pcap
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Pcap
PORTVERSION=	0.04
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE component for non-blocking use of Net::Pcap

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Net/Pcap.pm:${PORTSDIR}/net/p5-Net-Pcap \
		${SITE_PERL}/NetPacket/Ethernet.pm:${PORTSDIR}/net/p5-NetPacket
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Pcap.3

.include <bsd.port.mk>
