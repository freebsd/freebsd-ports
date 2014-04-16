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

USES=		gmake perl5
USE_PERL5=	configure

CUPS_RUN_DEPENDS=	p5-Net-CUPS>=0.6:${PORTSDIR}/print/p5-Net-CUPS
HTTP_RUN_DEPENDS=	p5-HTTP-Daemon>=0:${PORTSDIR}/www/p5-HTTP-Daemon
ZLIB_RUN_DEPENDS=	p5-Compress-Raw-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib
SSL_RUN_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
			p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https
DMIDECODE_RUN_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode
PCIUTILS_RUN_DEPENDS+=	lspci:${PORTSDIR}/sysutils/pciutils
MMAP_RUN_DEPENDS+=	nmap:${PORTSDIR}/security/nmap

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name '*.orig' \) -delete

.include <bsd.port.mk>
