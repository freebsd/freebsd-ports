# New ports collection makefile for:	SinFP
# Date created:		26 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SinFP
DISTVERSION=	2.02-1
CATEGORIES=	security ipv6 perl5
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Full operating system stack fingerprinting suite

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet
BUILD_DEPENDS=	p5-DBD-SQLite>=1.12:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1.50:${PORTSDIR}/databases/p5-DBI \
		p5-Bit-Vector>=6.4:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Carp-Clan>=5.3:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-Math-Base85>=0.2:${PORTSDIR}/math/p5-Math-Base85 \
		p5-Net-IPv4Addr>=0.10:${PORTSDIR}/net-mgmt/p5-Net-IPv4Addr \
		p5-Net-IPv6Addr>=0.2:${PORTSDIR}/net-mgmt/p5-Net-IPv6Addr \
		p5-Socket6>=0.19:${PORTSDIR}/net/p5-Socket6 \
		p5-Net-Libdnet>=0.01:${PORTSDIR}/net/p5-Net-Libdnet \
		p5-Net-Pcap>=0.12:${PORTSDIR}/net/p5-Net-Pcap \
		p5-Class-Gomor>=1.00:${PORTSDIR}/devel/p5-Class-Gomor \
		p5-DBIx-SQLite-Simple>=0.33:${PORTSDIR}/databases/p5-DBIx-SQLite-Simple \
		p5-Net-Write>=0.82:${PORTSDIR}/net/p5-Net-Write
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	p5-Net-Packet-[0-9]* p5-Net-Packet-Target-[0-9]*
MAN3=	Net::Packet.3 Net::Packet::ARP.3 Net::Packet::Consts.3 Net::Packet::Desc.3 \
	Net::Packet::DescL2.3 Net::Packet::DescL3.3 Net::Packet::DescL4.3 Net::Packet::Dump.3 \
	Net::Packet::ETH.3 Net::Packet::Env.3 Net::Packet::Frame.3 Net::Packet::ICMPv4.3 \
	Net::Packet::IPv4.3 Net::Packet::IPv6.3 Net::Packet::Layer.3 Net::Packet::Layer2.3 \
	Net::Packet::Layer3.3 Net::Packet::Layer4.3 Net::Packet::Layer7.3 Net::Packet::NULL.3 \
	Net::Packet::RAW.3 Net::Packet::SLL.3 Net::Packet::TCP.3 Net::Packet::Target.3 \
	Net::Packet::UDP.3 Net::Packet::Utils.3 Net::Packet::VLAN.3 Net::SinFP.3 Net::SinFP::Consts.3 \
	Net::SinFP::DB.3 Net::SinFP::DB::IpVersion.3 Net::SinFP::DB::Os.3 Net::SinFP::DB::OsVersion.3 \
	Net::SinFP::DB::OsVersionChildren.3 Net::SinFP::DB::OsVersionFamily.3 \
	Net::SinFP::DB::PatternBinary.3 Net::SinFP::DB::PatternTcpFlags.3 \
	Net::SinFP::DB::PatternTcpMss.3 Net::SinFP::DB::PatternTcpOptions.3 \
	Net::SinFP::DB::PatternTcpWindow.3 Net::SinFP::DB::Signature.3 Net::SinFP::DB::SystemClass.3 \
	Net::SinFP::DB::Vendor.3 Net::SinFP::Result.3 Net::SinFP::Search.3 Net::SinFP::SinFP4.3 \
	Net::SinFP::SinFP6.3

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	GOMOR_PATH=${PREFIX}

post-extract:
	@${MV} ${WRKSRC}/gomor/* ${WRKSRC}/
	@cd ${WRKSRC} && ${RM} -rf dbd-sqlite dbi libdnet libpcap modules net-libdnet net-pcap \
		Makefile Class* DBIx* Net-Write* gomor

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	perl 5.6.1 or newer required. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
