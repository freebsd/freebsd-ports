# New ports collection makefile for:   ocsinventory-agent
# Date created:				14 August 2007
# Whom:					Dennis Cabooter
#
# $FreeBSD$
#

PORTNAME=	Ocsinventory
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME:L}/OCS%20Inventory%20NG/${PORTVERSION}
PKGNAMESUFFIX=	-Agent
DISTNAME=	OCSNG_UNIX_AGENT-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Keep track of the computers configuration and software

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon
BUILD_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode \
		lspci:${PORTSDIR}/sysutils/pciutils

USE_PERL5=	yes
PERL_CONFIGURE=	yes
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-1.0.1

MAN1=		ocsinventory-agent.1

.include <bsd.port.mk>
