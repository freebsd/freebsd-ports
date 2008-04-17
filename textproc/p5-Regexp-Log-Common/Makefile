# New ports collection makefile for:	textproc/p5-Regexp-Log-Common
# Date created:				03 March 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Regexp-Log-Common
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Regexp::Log::Common, a parser for the Common Log Format

RUN_DEPENDS=	${SITE_PERL}/Regexp/Log.pm:${PORTSDIR}/textproc/p5-Regexp-Log
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Regexp::Log::Common.3

.include <bsd.port.mk>
