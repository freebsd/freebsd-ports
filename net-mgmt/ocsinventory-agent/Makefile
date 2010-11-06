# New ports collection makefile for:   ocsinventory-agent
# Date created:				14 August 2007
# Whom:					Dennis Cabooter
#
# $FreeBSD$
#

PORTNAME=	Ocsinventory
PORTVERSION=	1.1.2.1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://launchpad.net/ocsinventory-unix-agent/stable-1.1.2/ocsinventory-unix-agent-${PORTVERSION}/+download/
PKGNAMESUFFIX=	-Agent
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Keep track of the computers configuration and software

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon
BUILD_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode \
		lspci:${PORTSDIR}/sysutils/pciutils

FETCH_ARGS=
LICENSE=	GPLv2
USE_PERL5=	yes
PERL_CONFIGURE=	yes
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
MAN1=		ocsinventory-agent.1

.include <bsd.port.mk>
