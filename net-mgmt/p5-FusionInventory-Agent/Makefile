# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	FusionInventory-Agent
PORTVERSION=	2.2.5
CATEGORIES=	net-mgmt
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FUSINV
PKGNAMEPREFIX=	p5-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Agent for OCS Inventory server and FusionInventory for GLPI servers

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-ExtUtils-MakeMaker>=6.59:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-XML-TreePP>=0:${PORTSDIR}/textproc/p5-XML-TreePP \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-MockModule>=0:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-HTTP-Server-Simple-Authen>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple-Authen \
		p5-HTTP-Proxy>=0:${PORTSDIR}/www/p5-HTTP-Proxy \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-IO-Capture>=0:${PORTSDIR}/devel/p5-IO-Capture

OPTIONS_DEFINE=	CUPS HTTP ZLIB SSL DMIDECODE PCIUTILS NMAP
OPTIONS_DEFAULT=	ZLIB DMIDECODE PCIUTILS
HTTP_DESC=	HTTP daemon mode
ZLIB_DESC=	Zlib compression
DMIDECODE_DESC=	Dmidecode hardware information
PCIUTILS_DESC=	Pciutils hardware information

PERL_CONFIGURE=	yes
USE_GMAKE=	yes

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
RUN_DEPENDS+=		p5-Net-CUPS>=0.6:${PORTSDIR}/print/p5-Net-CUPS
.endif

.if ${PORT_OPTIONS:MHTTP}
RUN_DEPENDS+=		p5-HTTP-Daemon>=0:${PORTSDIR}/www/p5-HTTP-Daemon
.endif

.if ${PORT_OPTIONS:MZLIB}
RUN_DEPENDS+=		p5-Compress-Raw-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib
.endif

.if ${PORT_OPTIONS:MSSL}
RUN_DEPENDS+=		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
			p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https
.endif

.if ${PORT_OPTIONS:MDMIDECODE}
RUN_DEPENDS+=	dmidecode:${PORTSDIR}/sysutils/dmidecode
.endif

.if ${PORT_OPTIONS:MPCIUTILS}
RUN_DEPENDS+=	lspci:${PORTSDIR}/sysutils/pciutils
.endif

.if ${PORT_OPTIONS:MNMAP}
RUN_DEPENDS+=	nmap:${PORTSDIR}/security/nmap
.endif

post-patch-script:
	@${ECHO_MSG} -n ">> Removing unneeded patched files..."
	@${FIND} ${WRKSRC} -type f \( -name '*.orig' \) -delete
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@if [ ! -f ${PREFIX}/etc/fusioninventory/agent.cfg ]; then \
		${CP} -p ${PREFIX}/etc/fusioninventory/agent.cfg.sample ${PREFIX}/etc/fusioninventory/agent.cfg ; \
	fi

.include <bsd.port.mk>
