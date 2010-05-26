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
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Automatically handles the home OU for when adding/removing users

RUN_DEPENDS=	${SITE_PERL}/Plugtools.pm:${PORTSDIR}/sysutils/p5-Plugtools

PERL_CONFIGURE=	yes

MAN3=		Plugtools::Plugins::HomeOU.3 \
		Plugtools::Plugins::HomeOUremove.3

.include <bsd.port.mk>
