# Created by: Emil Smolenski <am@raisa.eu.org>
# $FreeBSD$

PORTNAME=	FusionInventory-Agent-Task-SNMPQuery
PORTVERSION=	1.3
CATEGORIES=	net-mgmt
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FUSINV
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SNMP support for FusionInventory Agent

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-FusionInventory-Agent>=0:${PORTSDIR}/net-mgmt/p5-FusionInventory-Agent \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>
