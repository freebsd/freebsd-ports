# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	FusionInventory-Agent
PORTVERSION=	2.3.17
CATEGORIES=	net-mgmt
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GROUSSE
PKGNAMEPREFIX=	p5-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Agent for OCS Inventory server and FusionInventory for GLPI servers

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>=6.59:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-XML-TreePP>=0:${PORTSDIR}/textproc/p5-XML-TreePP
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-POE-Component-Client-Ping>=0:${PORTSDIR}/net/p5-POE-Component-Client-Ping \
		p5-HTTP-Proxy>=0:${PORTSDIR}/www/p5-HTTP-Proxy \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-HTTP-Server-Simple-Authen>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple-Authen \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-IO-Capture>=0:${PORTSDIR}/devel/p5-IO-Capture \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-Test-Compile>=0:${PORTSDIR}/devel/p5-Test-Compile \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-MockModule>=0:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Simple>=0.93:${PORTSDIR}/devel/p5-Test-Simple

CONFLICTS=	p5-FusionInventory-Agent-Task-NetDiscovery-* \
		p5-FusionInventory-Agent-Task-SNMPQuery-*

OPTIONS_DEFINE=		CUPS DAEMON DMIDECODE DEPLOY NETDISC NETINV PCIUTILS \
			SSL VMWARE WOL ZLIB
OPTIONS_DEFAULT=	DMIDECODE PCIUTILS ZLIB
OPTIONS_SUB=	yes

DAEMON_DESC=	Daemon mode, with opt. web interface
DEPLOY_DESC=	Deployment task
DMIDECODE_DESC=	Dmidecode hardware information
NETDISC_DESC=	Network discovery task
NETINV_DESC=	Network inventory task
PCIUTILS_DESC=	Pciutils hardware information
VMWARE_DESC=	VMware hypervisor remote inventory task
WOL_DESC=	Wake on LAN task
ZLIB_DESC=	Zlib compression

USES=		gmake perl5
USE_PERL5=	configure
USE_RC_SUBR=    fusioninventory

CUPS_RUN_DEPENDS=	p5-Net-CUPS>=0.6:${PORTSDIR}/print/p5-Net-CUPS
DAEMON_RUN_DEPENDS=	p5-HTTP-Daemon>=0:${PORTSDIR}/www/p5-HTTP-Daemon \
			p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
			p5-Proc-PID-File>=0:${PORTSDIR}/devel/p5-Proc-PID-File
DEPLOY_RUN_DEPENDS=	p5-Archive-Extract>=0:${PORTSDIR}/archivers/p5-Archive-Extract \
			p5-SHA>=0:${PORTSDIR}/security/p5-SHA \
			p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
			p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
			p5-POE-Component-Client-Ping>=0:${PORTSDIR}/net/p5-POE-Component-Client-Ping \
			p5-URI-Escape-XS>=0:${PORTSDIR}/www/p5-URI-Escape-XS
# Wants URI::Escape, ports tree has URI::Escape::XS, seems drop-in replacement
DMIDECODE_RUN_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode
NETDISC_RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap \
			p5-Net-NBName>=0:${PORTSDIR}/net/p5-Net-NBName \
			p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
			p5-Thread-Queue>=0:${PORTSDIR}/devel/p5-Thread-Queue
NETINV_RUN_DEPENDS=	p5-Crypt-DES>=0:${PORTSDIR}/security/p5-Crypt-DES \
			p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
			p5-Thread-Queue>=0:${PORTSDIR}/devel/p5-Thread-Queue
PCIUTILS_RUN_DEPENDS+=	lspci:${PORTSDIR}/sysutils/pciutils
SSL_RUN_DEPENDS=	p5-IO-Socket-SSL>=1.14:${PORTSDIR}/security/p5-IO-Socket-SSL \
			p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https
WOL_RUN_DEPENDS=	p5-Net-Write>=0:${PORTSDIR}/net/p5-Net-Write
ZLIB_RUN_DEPENDS=	p5-Compress-Raw-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name '*.orig' \) -delete

.include <bsd.port.mk>
