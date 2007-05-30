# New ports collection makefile for:	p5-Catalyst-Plugin-Authentication-OpenID
# Date created:		2007-05-04
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Authentication-OpenID
PORTVERSION=	0.02
CATEGORIES=	www security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	OpenID Authentication

RUN_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/LWPx/ParanoidAgent.pm:${PORTSDIR}/www/p5-LWPx-ParanoidAgent \
		${SITE_PERL}/Net/OpenID/Consumer.pm:${PORTSDIR}/net/p5-Net-OpenID-Consumer
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::Authentication::OpenID.3

.include <bsd.port.mk>
