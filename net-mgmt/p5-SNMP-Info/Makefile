# New ports collection makefile for:	p5-SNMP-Info
# Date created:				2003-09-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	SNMP-Info
PORTVERSION=	0.8
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	snmp-info

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A perl5 module for gathering information from network devices

LIB_DEPENDS=	netsnmp.6:${PORTSDIR}/net-mgmt/net-snmp

PERL_CONFIGURE=	yes

MAN3=	SNMP::Info::CiscoVTP.3 SNMP::Info::MAU.3 SNMP::Info::Layer2::C2900.3 \
	SNMP::Info::Layer3::Aironet.3 SNMP::Info::Layer2::Catalyst.3 \
	SNMP::Info::Bridge.3 SNMP::Info::Layer2::Bay.3 \
	SNMP::Info::EtherLike.3 SNMP::Info::Layer2::ZyXEL_DSLAM.3 \
	SNMP::Info::Layer3::C6500.3 SNMP::Info::Layer1::Asante.3 \
	SNMP::Info::CiscoStats.3 SNMP::Info::Layer3::C3550.3 \
	SNMP::Info::Layer1.3 SNMP::Info::Layer3::Foundry.3 \
	SNMP::Info::Layer2::Aironet.3 SNMP::Info::Layer2.3 \
	SNMP::Info.3 SNMP::Info::Layer1::Allied.3 \
	SNMP::Info::Layer2::C1900.3 SNMP::Info::Layer3.3 \
	SNMP::Info::CiscoStack.3 SNMP::Info::Layer2::HP.3 SNMP::Info::CDP.3 \
	SNMP::Info::Entity.3

.include <bsd.port.mk>
