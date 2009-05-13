# New ports collection makefile for:	textproc/p5-HTML-Truncate
# Date created:				23 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Truncate
PORTVERSION=	0.19
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Truncate HTML by character count while preserving well-formedness

RUN_DEPENDS=	p5-HTML-Parser>=2:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Tagset>=3:${PORTSDIR}/www/p5-HTML-Tagset
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		HTML::Truncate.3

.include <bsd.port.mk>
