# New ports collection makefile for:	p5-Xango
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Xango
PORTVERSION=	1.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Event Based High Performance Web Crawler Framework

BUILD_DEPENDS=	${SITE_PERL}/Cache/Cache.pm:${PORTSDIR}/devel/p5-Cache-Cache \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTTP/Response.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/Client/DNS.pm:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		${SITE_PERL}/POE/Component/Client/HTTP.pm:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Xango.3 Xango::Broker.3 Xango::Broker::Base.3 \
		Xango::Broker::Pull.3 Xango::Broker::Push.3 \
		Xango::Config.3 Xango::Job.3 Xango::Manual::Intro.3

.include <bsd.port.mk>
