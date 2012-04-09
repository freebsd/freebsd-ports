# New ports collection makefile for:	p5-ZConf-Cron
# Date created:		2009-09-27
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-Cron
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Handles storing cron tabs in ZConf

BUILD_DEPENDS=	p5-DateTime-Event-Cron>=0:${PORTSDIR}/devel/p5-DateTime-Event-Cron \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-ZConf-GUI>=0:${PORTSDIR}/devel/p5-ZConf-GUI \
		p5-ZConf>=0:${PORTSDIR}/net/p5-ZConf
RUN_DEPENS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ZConf::Cron.3 \
		ZConf::Cron::GUI.3

.include <bsd.port.mk>
