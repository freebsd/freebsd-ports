# New ports collection makefile for:	POE-Component-Client-UserAgent
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-UserAgent
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RC/RCAPUTO
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	LWP and LWP::Parallel based POE component

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/LWP/Parallel.pm:${PORTSDIR}/www/p5-ParallelUA
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::UserAgent.3

.include <bsd.port.mk>
