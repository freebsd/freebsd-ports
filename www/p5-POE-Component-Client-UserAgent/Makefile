# New ports collection makefile for:	POE-Component-Client-UserAgent
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-UserAgent
PORTVERSION=	0.04
CATEGORIES=	devel perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RC/RCAPUTO
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/Parallel.pm:${PORTSDIR}/www/p5-ParallelUA
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		POE::Component::Client::UserAgent.3

.include <bsd.port.mk>
