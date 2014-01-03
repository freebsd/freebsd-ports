# $FreeBSD$

PORTNAME=	Ocsinventory
PORTVERSION=	2.0.5
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://launchpad.net/ocsinventory-unix-agent/stable-2.0/${PORTVERSION}/+download/
PKGNAMESUFFIX=	-Unix-Agent
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keep track of the computers configuration and software

LICENSE=	GPLv2

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon
BUILD_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode \
		lspci:${PORTSDIR}/sysutils/pciutils

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
MAN1=		ocsinventory-agent.1
MAN3=		Ocsinventory::Agent::XML::Inventory.3 \
		Ocsinventory::Agent::Common.3
SUB_FILES=	pkg-message
SUB_LIST=	SITE_PERL=${SITE_PERL}

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
