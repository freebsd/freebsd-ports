PORTNAME=	ocsinventory
PORTVERSION=	2.8.1
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-agent

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Keep track of the computers configuration and software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dmidecode:sysutils/dmidecode \
		lspci:sysutils/pciutils \
		p5-libwww>=0:www/p5-libwww \
		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
		p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
		p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_PROJECT=	UnixAgent
GH_ACCOUNT=	OCSInventory-NG
USE_PERL5=	configure
CONFIGURE_ENV=	PERL_AUTOINSTALL=1
SUB_FILES=	pkg-message
SUB_LIST=	SITE_PERL=${PREFIX}/${SITE_PERL_REL}
NO_ARCH=	yes

SHEBANG_FILES=	postinst.pl

# define options
OPTIONS_DEFINE=	DAEMON IPMI PRINTER SNMP SSL

DAEMON_DESC=	Daemon mode
IPMI_DESC=	Collect information about IPMI
PRINTER_DESC=	Printers detection
SNMP_DESC=	Scan network devices using SNMP

# define default options
OPTIONS_DEFAULT=	SNMP SSL

DAEMON_RUN_DEPENDS=	p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
			p5-Proc-PID-File>=0:devel/p5-Proc-PID-File
IPMI_RUN_DEPENDS=	ipmitool:sysutils/ipmitool
SSL_RUN_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
			p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https
PRINTER_RUN_DEPENDS=	p5-Net-CUPS>=0:print/p5-Net-CUPS
SNMP_RUN_DEPENDS=	nmap:security/nmap \
			p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask \
			p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
			p5-Nmap-Parser>=0:security/p5-Nmap-Parser

.include <bsd.port.mk>
