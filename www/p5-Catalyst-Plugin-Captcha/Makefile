# New ports collection makefile for:	Catalyst-Plugin-Captcha
# Date created:	   05 August 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Captcha
PORTVERSION=	0.04
CATEGORIES=	www security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Create and validate Captcha for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/Catalyst/Plugin/Session.pm:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/GD/SecurityImage.pm:${PORTSDIR}/security/p5-GD-SecurityImage
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::Captcha.3

.include <bsd.port.mk>
