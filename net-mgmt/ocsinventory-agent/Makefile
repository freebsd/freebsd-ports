# New ports collection makefile for:   ocsinventory-agent
# Date created:				14 August 2007
# Whom:					Dennis Cabooter
#
# $FreeBSD$
#

PORTNAME=	Ocsinventory
PORTVERSION=	2.0
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://launchpad.net/ocsinventory-unix-agent/stable-${PORTVERSION}/${PORTVERSION}/+download/
PKGNAMESUFFIX=	-Agent
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Keep track of the computers configuration and software

LICENSE=	GPLv2

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon
BUILD_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode \
		lspci:${PORTSDIR}/sysutils/pciutils

FETCH_ARGS=
USE_PERL5=	yes
PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
MAN1=		ocsinventory-agent.1
MAN3=		Ocsinventory::Agent::XML::Inventory.3 \
		Ocsinventory::Agent::Common.3
SUB_FILES=	pkg-message
SUB_LIST=	SITE_PERL=${SITE_PERL}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
