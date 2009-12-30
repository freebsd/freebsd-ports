# New ports collection makefile for:	p5-Beanstalk-Client
# Date created:		2009-11-12
# Whom:			Vsevolod Stakhov <vsevolod@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Beanstalk-Client
PORTVERSION=	1.06
CATEGORIES=	net perl5
MASTER_SITES=	CPAN/../../authors/id/G/GB/GBARR/
PKGNAMEPREFIX=	p5-

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Perl API for beanstalkd, a distributed queue daemon

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/YAML/Syck.pm:${PORTSDIR}/textproc/p5-YAML-Syck \
				${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
				${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error

PERL_CONFIGURE=	yes

MAN3=	Beanstalk::Client.3 \
		Beanstalk::Pool.3 \
		Beanstalk::Stats.3 \
		Beanstalk::Job.3

.include <bsd.port.mk>
