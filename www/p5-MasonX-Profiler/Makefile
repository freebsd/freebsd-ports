# New ports collection makefile for:	p5-MasonX-Profiler
# Date created:			20 Sep 2004
# Whom:				mat
#
# $FreeBSD$
#

PORTNAME=	MasonX-Profiler
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mason per-component profiler

BUILD_DEPENDS=	${SITE_PERL}/HTML/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MasonX::Profiler.3

.include <bsd.port.mk>
