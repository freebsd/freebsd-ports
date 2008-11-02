# New ports collection makefile for:	p5-Socket6
# Date created:		24 May 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Socket6
PORTVERSION=	0.23
CATEGORIES=	net perl5 ipv6
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ume@FreeBSD.org
COMMENT=	IPv6 related part of the C socket.h defines and structure manipulators

PERL_CONFIGURE=	yes

PLIST_FILES=	%%SITE_PERL%%/%%PERL_ARCH%%/Socket6.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Socket6/.packlist \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Socket6/Socket6.bs \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Socket6/Socket6.so
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Socket6

.include <bsd.port.mk>
