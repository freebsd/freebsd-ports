# New ports collection makefile for:	p5-ZConf-Cron
# Date created:		2009-09-27
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-Cron
PORTVERSION=	1.0.1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Handles storing cron tabs in ZConf

BUILD_DEPENDS=	${SITE_PERL}/ZConf.pm:${PORTSDIR}/net/p5-ZConf \
		${SITE_PERL}/DateTime/Event/Cron.pm:${PORTSDIR}/devel/p5-DateTime-Event-Cron \
		${SITE_PERL}/mach/DateTime/Duration.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Format/Strptime.pm:${PORTSDIR}/devel/p5-DateTime-Format-Strptime

PERL_CONFIGURE=	yes

MAN3=		ZConf::Cron.3 \
		ZConf::Cron::GUI.3

.include <bsd.port.mk>
