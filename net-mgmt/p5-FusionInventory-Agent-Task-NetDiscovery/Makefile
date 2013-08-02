# Created by: Emil Smolenski <am@raisa.eu.org>
# $FreeBSD$

PORTNAME=	FusionInventory-Agent-Task-NetDiscovery
PORTVERSION=	1.5
CATEGORIES=	net-mgmt
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FUSINV
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network discovery support for FusionInventory Agent

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-FusionInventory-Agent>=0:${PORTSDIR}/net-mgmt/p5-FusionInventory-Agent \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Net-NBName>=0:${PORTSDIR}/net/p5-Net-NBName \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XML-TreePP>=0:${PORTSDIR}/textproc/p5-XML-TreePP
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		FusionInventory::Agent::Task::NetDiscovery.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

post-patch:
	${RM} ${WRKSRC}/lib/FusionInventory/Agent/Task/NetDiscovery.pm.orig

.include <bsd.port.post.mk>
