# Ports collection makefile for:	p5-Catalyst-Plugin-Scheduler
# Date created:				25.Mar.2007
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Scheduler
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Schedule events to run in a cron-like manner

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-DateTime-Event-Cron>=0:${PORTSDIR}/devel/p5-DateTime-Event-Cron \
		p5-Set-Scalar>=0:${PORTSDIR}/devel/p5-Set-Scalar \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Plugin::Scheduler.3

.include <bsd.port.mk>
