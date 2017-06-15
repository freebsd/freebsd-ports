# $FreeBSD$

PORTNAME=	Ocsinventory
PORTVERSION=	2.1.1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://launchpad.net/ocsinventory-unix-agent/stable-${PORTVERSION:R}/${PORTVERSION}/+download/
PKGNAMESUFFIX=	-Unix-Agent
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keep track of the computers configuration and software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lspci:sysutils/pciutils \
		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
		p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww

USES=		perl5 shebangfix
SHEBANG_FILES=	postinst.pl
USE_PERL5=	configure
CONFIGURE_ENV=	PERL_AUTOINSTALL=1
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
SUB_FILES=	pkg-message
SUB_LIST=	SITE_PERL=${PREFIX}/${SITE_PERL_REL}
NO_ARCH=	yes

# define options
OPTIONS_DEFINE=	DAEMON IPMI SSL PRINTER SNMP

DAEMON_DESC=	Daemon mode
IPMI_DESC=	Collect information about IPMI
PRINTER_DESC=	Printers detection
SNMP_DESC=	Scan network devices using SNMP

# define default options
OPTIONS_DEFAULT=	SSL SNMP

DAEMON_RUN_DEPENDS=	p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
			p5-Proc-PID-File>=0:devel/p5-Proc-PID-File
IPMI_RUN_DEPENDS=	ipmitool:sysutils/ipmitool
SSL_RUN_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
			p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https
PRINTER_RUN_DEPENDS=	p5-Net-CUPS>=0:print/p5-Net-CUPS
SNMP_RUN_DEPENDS=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
			p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask \
			p5-Nmap-Parser>=0:security/p5-Nmap-Parser \
			nmap:security/nmap

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
RUN_DEPENDS+=	dmidecode:sysutils/dmidecode
.endif
.include <bsd.port.post.mk>
