# New ports collection makefile for:	sysutils/p5-Plugtools-Plugins-HomeOU
# Date created:		2010-02-26
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Plugtools-Plugins-HomeOU
PORTVERSION=	0.0.0
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Automatically handles the home OU for when adding/removing users

RUN_DEPENDS=	p5-Plugtools>=0:${PORTSDIR}/sysutils/p5-Plugtools

USES=		perl5
USE_PERL5=	configure

MAN3=		Plugtools::Plugins::HomeOU.3 \
		Plugtools::Plugins::HomeOUremove.3

.include <bsd.port.mk>
