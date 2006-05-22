# New ports collection makefile for:	Net-Packet
# Date created:				01 Feb 2005
# Whom:					GomoR <netpkt@gomor.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Packet
PORTVERSION=	2.22
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	netpkt@gomor.org
COMMENT=	A framework to easily send and receive frames from layer 2 to layer 7

BUILD_DEPENDS=	${SITE_PERL}/Class/Gomor/Hash.pm:${PORTSDIR}/devel/p5-Class-Gomor \
		${SITE_PERL}/${PERL_ARCH}/Net/Write/Layer2.pm:${PORTSDIR}/net/p5-Net-Write \
		${SITE_PERL}/${PERL_ARCH}/IO/Interface.pm:${PORTSDIR}/net/p5-IO-Interface \
		${SITE_PERL}/Net/IPv6Addr.pm:${PORTSDIR}/net-mgmt/p5-Net-IPv6Addr \
		${SITE_PERL}/${PERL_ARCH}/Net/Pcap.pm:${PORTSDIR}/net/p5-Net-Pcap \
		${SITE_PERL}/${PERL_ARCH}/Socket6.pm:${PORTSDIR}/net/p5-Socket6 \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386

MAN3=		Net::Packet.3 \
		Net::Packet::ARP.3 \
		Net::Packet::Consts.3 \
		Net::Packet::Desc.3 \
		Net::Packet::DescL2.3 \
		Net::Packet::DescL3.3 \
		Net::Packet::DescL4.3 \
		Net::Packet::Dump.3 \
		Net::Packet::ETH.3 \
		Net::Packet::Env.3 \
		Net::Packet::Frame.3 \
		Net::Packet::ICMPv4.3 \
		Net::Packet::IPv4.3 \
		Net::Packet::IPv6.3 \
		Net::Packet::Layer.3 \
		Net::Packet::Layer2.3 \
		Net::Packet::Layer3.3 \
		Net::Packet::Layer4.3 \
		Net::Packet::Layer7.3 \
		Net::Packet::NULL.3 \
		Net::Packet::RAW.3 \
		Net::Packet::SLL.3 \
		Net::Packet::TCP.3 \
		Net::Packet::UDP.3 \
		Net::Packet::Utils.3 \
		Net::Packet::VLAN.3 \
		Net::Pkt.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or higher. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
