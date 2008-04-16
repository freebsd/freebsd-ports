# New ports collection makefile for:	textproc/p5-Pod-Spell
# Date created:				16 April 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pod-Spell
PORTVERSION=	1.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A formatter for spellchecking Pod

BUILD_DEPENDS=	p5-Pod-Escapes>=1.01:${PORTSDIR}/textproc/p5-Pod-Escapes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Pod::Spell.3 \
	Pod::Wordlist.3

.include <bsd.port.mk>
