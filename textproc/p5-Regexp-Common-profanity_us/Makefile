# New ports collection makefile for:	p5-Regexp-Common-profanity_us
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Regexp-Common-profanity_us
PORTVERSION=	2.2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Provide regexes for U.S. profanity

BUILD_DEPENDS=	${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Regexp::Common::profanity_us.3 \
		Regexp::Profanity::US.3

.include <bsd.port.mk>
