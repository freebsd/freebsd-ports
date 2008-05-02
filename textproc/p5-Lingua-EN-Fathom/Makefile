# New ports collection makefile for:	textproc/p5-Lingua-EN-Fathom
# Date created:				28 February 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-Fathom
PORTVERSION=	1.12
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Lingua::EN::Fathom - Measure readability of English text

BUILD_DEPENDS=	${SITE_PERL}/Lingua/EN/Syllable.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Syllable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::Fathom.3

.include <bsd.port.mk>
