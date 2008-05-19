# New ports collection makefile for:	Catalyst-View-Templated
# Date created:	   18 Jan 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-Templated
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/J/JR/JROCKWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Generic base class for template-based views

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/Catalyst/Component/ACCEPT_CONTEXT.pm:${PORTSDIR}/www/p5-Catalyst-Component-ACCEPT_CONTEXT \
		${SITE_PERL}/Class/C3.pm:${PORTSDIR}/devel/p5-Class-C3
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::View::Templated.3

.include <bsd.port.mk>
