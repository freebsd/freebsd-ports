# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	FreeBSD-Pkgs-FindUpdates
PORTVERSION=	0.3.0
CATEGORIES=	ports-mgmt sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Finds updates for FreeBSD pkgs by checking the ports index

BUILD_DEPENDS=	p5-Error-Helper>=0:${PORTSDIR}/devel/p5-Error-Helper \
		p5-FreeBSD-Pkgs>=0:${PORTSDIR}/ports-mgmt/p5-FreeBSD-Pkgs \
		p5-FreeBSD-Ports-INDEXhash>=0:${PORTSDIR}/ports-mgmt/p5-FreeBSD-Ports-INDEXhash \
		p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
