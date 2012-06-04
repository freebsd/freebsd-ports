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

BUILD_DEPENDS=	p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MasonX::Profiler.3

.include <bsd.port.mk>
