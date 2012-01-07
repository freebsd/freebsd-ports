# New ports collection makefile for:	p5-FusionInventory-Agent
# Date created:		2011-08-18
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	FusionInventory-Agent
PORTVERSION=	2.1.13
CATEGORIES=	net-mgmt
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FUSINV
PKGNAMEPREFIX=	p5-

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Agent for OCS Inventory server and FusionInventory for GLPI servers

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-HTTP-Daemon>=0:${PORTSDIR}/www/p5-HTTP-Daemon \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-HTTP-Server-Simple-Authen>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple-Authen \
		p5-Net-CUPS>=0.6:${PORTSDIR}/print/p5-Net-CUPS \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-Proc-PID-File>=0:${PORTSDIR}/devel/p5-Proc-PID-File \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XML-TreePP>=0:${PORTSDIR}/textproc/p5-XML-TreePP \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	dmidecode:${PORTSDIR}/sysutils/dmidecode \
		lspci:${PORTSDIR}/sysutils/pciutils \
		nmap:${PORTSDIR}/security/nmap

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN1=		fusioninventory-agent-config.1 \
		fusioninventory-agent.1 \
		fusioninventory-injector.1
MAN3=		FusionInventory::Agent::Network.3 \
		FusionInventory::Agent::RPC.3 \
		FusionInventory::Agent::Storage.3 \
		FusionInventory::Agent::Task::Inventory.3 \
		FusionInventory::Agent::Tools.3 \
		FusionInventory::Agent::Tools::MacOS.3 \
		FusionInventory::Agent::Tools::Win32.3 \
		FusionInventory::Agent::XML::Query::Inventory.3 \
		FusionInventory::Agent::XML::Query::SimpleMessage.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
