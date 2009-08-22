# New ports collection makefile for:	p5-SNMP-Info
# Date created:				2003-09-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	SNMP-Info
PORTVERSION=	2.01
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	SF
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A perl5 module for gathering information from network devices

LIB_DEPENDS=	netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp

PERL_CONFIGURE=	yes

MAN3=	SNMP::Info.3 SNMP::Info::Airespace.3 SNMP::Info::Layer3::Altiga.3 \
	SNMP::Info::Layer3::Arista.3 SNMP::Info::Bridge.3 \
	SNMP::Info::CDP.3 SNMP::Info::CiscoImage.3 SNMP::Info::CiscoQOS.3 \
	SNMP::Info::CiscoRTT.3 SNMP::Info::CiscoStack.3 \
	SNMP::Info::CiscoStats.3 SNMP::Info::CiscoStpExtensions.3 \
	SNMP::Info::CiscoVTP.3 SNMP::Info::Entity.3 \
	SNMP::Info::EtherLike.3 SNMP::Info::FDP.3 SNMP::Info::Layer1.3 \
	SNMP::Info::Layer1::Allied.3 SNMP::Info::Layer1::Asante.3 \
	SNMP::Info::Layer1::Bayhub.3 SNMP::Info::Layer1::S3000.3 \
	SNMP::Info::Layer2.3 SNMP::Info::Layer2::Aironet.3 \
	SNMP::Info::Layer2::Allied.3 SNMP::Info::Layer2::Aruba.3 \
	SNMP::Info::Layer2::Bay.3 SNMP::Info::Layer2::Baystack.3 \
	SNMP::Info::Layer2::C1900.3 SNMP::Info::Layer2::C2900.3 \
	SNMP::Info::Layer2::Catalyst.3 SNMP::Info::Layer2::Centillion.3 \
	SNMP::Info::Layer2::Cisco.3 SNMP::Info::Layer2::Foundry.3 \
	SNMP::Info::Layer2::HP.3 SNMP::Info::Layer2::N2270.3 \
	SNMP::Info::Layer2::NAP222x.3 SNMP::Info::Layer2::Orinoco.3 \
	SNMP::Info::Layer2::ZyXEL_DSLAM.3 SNMP::Info::Layer3.3 \
	SNMP::Info::Layer3::Aironet.3 SNMP::Info::Layer3::AlteonAD.3 \
	SNMP::Info::Layer3::BayRS.3 SNMP::Info::Layer3::C3550.3 \
	SNMP::Info::Layer3::C4000.3 SNMP::Info::Layer3::C6500.3 \
	SNMP::Info::Layer3::Cisco.3 SNMP::Info::Layer3::Contivity.3 \
	SNMP::Info::Layer3::Extreme.3 SNMP::Info::Layer3::Foundry.3 \
	SNMP::Info::Layer3::N1600.3 SNMP::Info::Layer3::Passport.3 \
	SNMP::Info::MAU.3 SNMP::Info::NortelStack.3 SNMP::Info::RapidCity.3 \
	SNMP::Info::SONMP.3 SNMP::Info::Layer3::Juniper.3 \
	SNMP::Info::CiscoConfig.3 SNMP::Info::CiscoPortSecurity.3 \
	SNMP::Info::CiscoPower.3 SNMP::Info::IEEE802dot11.3 SNMP::Info::LLDP.3 \
	SNMP::Info::Layer1::Cyclades.3 SNMP::Info::Layer2::Airespace.3 \
	SNMP::Info::Layer2::Netgear.3 SNMP::Info::Layer3::Dell.3 \
	SNMP::Info::Layer3::Enterasys.3 SNMP::Info::Layer3::Microsoft.3 \
	SNMP::Info::Layer3::NetSNMP.3 SNMP::Info::Layer3::Netscreen.3\
	SNMP::Info::Layer3::Sun.3 SNMP::Info::PowerEthernet.3 \
	SNMP::Info::Layer3::HP9300.3 SNMP::Info::Layer3::AlcatelLucent.3 \
	SNMP::Info::Layer3::Timetra.3

.include <bsd.port.mk>
