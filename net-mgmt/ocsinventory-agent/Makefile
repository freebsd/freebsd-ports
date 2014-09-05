# $FreeBSD$

PORTNAME=	Ocsinventory
PORTVERSION=	2.1.1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://launchpad.net/ocsinventory-unix-agent/stable-2.1/${PORTVERSION}/+download/
PKGNAMESUFFIX=	-Unix-Agent
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keep track of the computers configuration and software

LICENSE=	GPLv2

RUN_DEPENDS=	lspci:${PORTSDIR}/sysutils/pciutils \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		dmidecode:${PORTSDIR}/sysutils/dmidecode \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	PERL_AUTOINSTALL=1
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
SUB_FILES=	pkg-message
SUB_LIST=	SITE_PERL=${SITE_PERL}

# define options
OPTIONS_DEFINE=	DAEMON IPMI SSL PRINTER SNMP

DAEMON_DESC=	Daemon mode
IPMI_DESC=	Collect information about IPMI
SSL_DESC=	Get SSL communications working
PRINTER_DESC=	Printers detection
SNMP_DESC=	Scan network devices using SNMP

# define default options
OPTIONS_DEFAULT=	SSL SNMP

DAEMON_RUN_DEPENDS=	p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
			p5-Proc-PID-File>=0:${PORTSDIR}/devel/p5-Proc-PID-File
IPMI_RUN_DEPENDS=	ipmitool:${PORTSDIR}/sysutils/ipmitool
SSL_RUN_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
			p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https
PRINTER_RUN_DEPENDS=	p5-Net-CUPS>=0:${PORTSDIR}/print/p5-Net-CUPS
SNMP_RUN_DEPENDS=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
			p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
			p5-Net-Ping>=0:${PORTSDIR}/net/p5-Net-Ping \
			p5-Nmap-Parser>=0:${PORTSDIR}/security/p5-Nmap-Parser \
			nmap:${PORTSDIR}/security/nmap

.include <bsd.port.mk>
