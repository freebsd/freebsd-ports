# New ports collection makefile for:	p5-LWP-UserAgent-WithCache
# Date created:		2007-10-12
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	LWP-UserAgent-WithCache
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	LWP::UserAgent extension with local cache

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww	\
		${SITE_PERL}/Cache/FileCache.pm:${PORTSDIR}/devel/p5-Cache-Cache
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		LWP::UserAgent::WithCache.3

.include <bsd.port.mk>
