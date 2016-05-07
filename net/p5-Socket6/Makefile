# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Socket6
PORTVERSION=	0.27
#PORTREVISION=	0
CATEGORIES=	net perl5 ipv6
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:UMEMOTO
PKGNAMEPREFIX=	p5-

MAINTAINER=	ume@FreeBSD.org
COMMENT=	IPv6 related part of the C socket.h defines and structure manipulators

LICENSE=	BSD3CLAUSE

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV+=	CC="${CC}"

PLIST_FILES=	%%PERL5_MAN3%%/Socket6.3.gz \
		%%SITE_ARCH%%/Socket6.pm \
		%%SITE_ARCH%%/auto/Socket6/Socket6.so

.include <bsd.port.mk>
