# New ports collection makefile for:	p5-FusionInventory-Agent
# Date created:		2011-08-18
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	FusionInventory-Agent
PORTVERSION=	2.2.4
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
MAN3PREFIX=	${PREFIX}

MAN1=		fusioninventory-agent.1 \
		fusioninventory-injector.1

MAN3=		FusionInventory::Agent.3 \
		FusionInventory::Agent::Config.3 \
		FusionInventory::Agent::HTTP::Client.3 \
		FusionInventory::Agent::HTTP::Client::Fusion.3 \
		FusionInventory::Agent::HTTP::Client::OCS.3 \
		FusionInventory::Agent::HTTP::Protocol::https.3 \
		FusionInventory::Agent::HTTP::Server.3 \
		FusionInventory::Agent::Logger.3 \
		FusionInventory::Agent::Logger::Backend.3 \
		FusionInventory::Agent::Logger::File.3 \
		FusionInventory::Agent::Logger::Stderr.3 \
		FusionInventory::Agent::Logger::Syslog.3 \
		FusionInventory::Agent::Scheduler.3 \
		FusionInventory::Agent::Storage.3 \
		FusionInventory::Agent::Target.3 \
		FusionInventory::Agent::Target::Local.3 \
		FusionInventory::Agent::Target::Server.3 \
		FusionInventory::Agent::Target::Stdout.3 \
		FusionInventory::Agent::Task.3 \
		FusionInventory::Agent::Task::Inventory.3 \
		FusionInventory::Agent::Task::Inventory::Inventory.3 \
		FusionInventory::Agent::Task::WakeOnLan.3 \
		FusionInventory::Agent::Tools.3 \
		FusionInventory::Agent::Tools::AIX.3 \
		FusionInventory::Agent::Tools::Generic.3 \
		FusionInventory::Agent::Tools::HPUX.3 \
		FusionInventory::Agent::Tools::Hostname.3 \
		FusionInventory::Agent::Tools::Linux.3 \
		FusionInventory::Agent::Tools::MacOS.3 \
		FusionInventory::Agent::Tools::Network.3 \
		FusionInventory::Agent::Tools::Screen.3 \
		FusionInventory::Agent::Tools::Solaris.3 \
		FusionInventory::Agent::Tools::Unix.3 \
		FusionInventory::Agent::Tools::Win32.3 \
		FusionInventory::Agent::XML::Query.3 \
		FusionInventory::Agent::XML::Query::Inventory.3 \
		FusionInventory::Agent::XML::Query::Prolog.3 \
		FusionInventory::Agent::XML::Response.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
