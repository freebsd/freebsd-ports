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

RUN_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-LWPx-ParanoidAgent>=0:${PORTSDIR}/www/p5-LWPx-ParanoidAgent \
		p5-Net-OpenID-Consumer>=0:${PORTSDIR}/net/p5-Net-OpenID-Consumer
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Catalyst::Plugin::Authentication::OpenID.3

.include <bsd.port.mk>
