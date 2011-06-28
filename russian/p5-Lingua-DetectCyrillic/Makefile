# New ports collection makefile for:	p5-Lingua-DetectCyrillic
# Date created:		Jun 15 2011
# Whom:			Dmitry Liakh <dliakh@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	Lingua-DetectCyrillic
PORTVERSION=	0.02
CATEGORIES=	russian perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dliakh@ukr.net
COMMENT=	Detects 7 Cyrillic codings as well as the language

RUN_DEPENDS=	p5-Unicode-Map8>=0:${PORTSDIR}/converters/p5-Unicode-Map8 \
		p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String

PERL_CONFIGURE=	yes

MAN3=		Lingua::DetectCyrillic.3

.include <bsd.port.mk>
