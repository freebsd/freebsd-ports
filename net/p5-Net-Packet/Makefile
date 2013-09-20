# Created by: GomoR <netpkt@gomor.org>
# $FreeBSD$

PORTNAME=	Net-Packet
DISTVERSION=	3.27
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	netpkt@gomor.org
COMMENT=	Send and receive frames from layer 2 to layer 7

BUILD_DEPENDS=	p5-Bit-Vector>=6.4:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Class-Gomor>=1.00:${PORTSDIR}/devel/p5-Class-Gomor \
		p5-Net-IPv6Addr>=0.2:${PORTSDIR}/net-mgmt/p5-Net-IPv6Addr \
		p5-Net-Libdnet>=0.01:${PORTSDIR}/net/p5-Net-Libdnet \
		p5-Net-Write>=1.00:${PORTSDIR}/net/p5-Net-Write \
		p5-Net-Pcap>=0.14:${PORTSDIR}/net/p5-Net-Pcap \
		p5-Socket6>=0.19:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

MAN3=	Net::Packet.3 Net::Packet::ARP.3 Net::Packet::CDP.3 Net::Packet::CDP::Address.3 \
Net::Packet::CDP::Type.3 Net::Packet::CDP::TypeAddresses.3 Net::Packet::CDP::TypeCapabilities.3 \
Net::Packet::CDP::TypeDeviceId.3 Net::Packet::CDP::TypePortId.3 \
Net::Packet::CDP::TypeSoftwareVersion.3 Net::Packet::Consts.3 Net::Packet::Desc.3 \
Net::Packet::DescL2.3 Net::Packet::DescL3.3 Net::Packet::DescL4.3 Net::Packet::Dump.3 \
Net::Packet::ETH.3 Net::Packet::Env.3 Net::Packet::Frame.3 Net::Packet::ICMPv4.3 Net::Packet::IGMPv4.3 \
Net::Packet::IPv4.3 Net::Packet::IPv6.3 Net::Packet::LLC.3 Net::Packet::Layer.3 Net::Packet::Layer2.3 \
Net::Packet::Layer3.3 Net::Packet::Layer4.3 Net::Packet::Layer7.3 Net::Packet::NULL.3 \
Net::Packet::OSPF.3 Net::Packet::PPP.3 Net::Packet::PPPLCP.3 Net::Packet::PPPoE.3 Net::Packet::RAW.3 \
Net::Packet::SLL.3 Net::Packet::STP.3 Net::Packet::TCP.3 Net::Packet::UDP.3 Net::Packet::Utils.3 \
Net::Packet::VLAN.3

.if !defined(NOPORTEXAMPLES)
NO_STAGE=	yes
post-install:
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
