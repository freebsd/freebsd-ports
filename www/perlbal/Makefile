# New ports collection makefile for:	perlbal
# Date created:		2005-08-08
# Whom:			Jacques Marneweck <jacques@php.net>
#
# $FreeBSD$
#

PORTNAME=	Perlbal
PORTVERSION=	1.78
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=../../authors/id/D/DO/DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reverse-proxy load balancer and webserver

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/BSD/Resource.pm:${PORTSDIR}/devel/p5-BSD-Resource \
		${SITE_PERL}/Danga/Socket.pm:${PORTSDIR}/devel/p5-Danga-Socket \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
USE_RC_SUBR=	perlbal

MAN1=		perlbal.1
MAN3=		Perlbal.3 \
		Perlbal::Plugin::Palimg.3 \
		Perlbal::Plugin::Cgilike.3 \
		Perlbal::Plugin::Include.3 \
		Perlbal::Plugin::Redirect.3 \
		Perlbal::Plugin::MaxContentLength.3 \
		Perlbal::Test.3 \
		Perlbal::Util.3 \
		Perlbal::FAQ.3 \
		Perlbal::Manual.3 \
		Perlbal::Manual::Configuration.3 \
		Perlbal::Manual::Contributing.3 \
		Perlbal::Manual::Credits.3 \
		Perlbal::Manual::Debugging.3 \
		Perlbal::Manual::FailOver.3 \
		Perlbal::Manual::HighPriority.3 \
		Perlbal::Manual::Hooks.3 \
		Perlbal::Manual::Install.3 \
		Perlbal::Manual::Internals.3 \
		Perlbal::Manual::LoadBalancer.3 \
		Perlbal::Manual::Logging.3 \
		Perlbal::Manual::Management.3 \
		Perlbal::Manual::Plugins.3 \
		Perlbal::Manual::ReverseProxy.3 \
		Perlbal::Manual::Roles.3 \
		Perlbal::Manual::Selector.3 \
		Perlbal::Manual::WebServer.3

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
