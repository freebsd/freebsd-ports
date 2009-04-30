# New ports collection makefile for:	p5-FreeBSD-Pkgs-Findupdates
# Date created:		2009-04-01
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	FreeBSD-Pkgs-FindUpdates
PORTVERSION=	0.2.1
CATEGORIES=	ports-mgmt sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Finds updates for FreeBSD pkgs by checking the ports index

RUN_DEPENDS=	${SITE_PERL}/FreeBSD/Ports/INDEXhash.pm:${PORTSDIR}/ports-mgmt/p5-FreeBSD-Ports-INDEXhash \
		${SITE_PERL}/FreeBSD/Pkgs.pm:${PORTSDIR}/ports-mgmt/p5-FreeBSD-Pkgs \
		${SITE_PERL}/Sort/Versions.pm:${PORTSDIR}/devel/p5-Sort-Versions

PERL_CONFIGURE=	yes

MAN3=		FreeBSD::Pkgs::FindUpdates.3

.include <bsd.port.mk>
