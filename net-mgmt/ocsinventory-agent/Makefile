# New ports collection makefile for:   ocsinventory-agent
# Date created:				14 August 2007
# Whom:					Dennis Cabooter
#
# $FreeBSD$
#

PORTNAME=	Ocsinventory
PORTVERSION=	0.0.6.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nana.rulezlan.org/~goneri/ocsinventory-agent/
PKGNAMESUFFIX=	-Agent
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	freebsd@rootxs.org
COMMENT=	Keep track of the computers configuration and software

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon \
		dmidecode:${PORTSDIR}/sysutils/dmidecode \
		lspci:${PORTSDIR}/sysutils/pciutils

USE_PERL5=	yes
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
