# New ports collection makefile for:	textproc/p5-Text-Filter-Chain
# Date created:				29 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Filter-Chain
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Chains multiple Text::Filter objects and runs them in sequence

BUILD_DEPENDS=	${SITE_PERL}/Text/Filter.pm:${PORTSDIR}/textproc/p5-Text-Filter

PERL_CONFIGURE=	yes

MAN3=		Text::Filter::Chain.3

.include <bsd.port.mk>
