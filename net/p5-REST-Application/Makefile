# New ports collection makefile for:	p5-REST-Application
# Date created:				04 June 2007
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	REST-Application
PORTVERSION=	0.992
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MO/MOCONNOR
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A framework for building RESTful web-applications

BUILD_DEPENDS=	p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	REST::Application.3 \
	REST::Application::Routes.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
