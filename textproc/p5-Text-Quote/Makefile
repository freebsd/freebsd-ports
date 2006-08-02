# ex:ts=8
# Ports collection makefile for:	Text::Quote
# Date created:			Jul 29, 2006
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Text-Quote
PORTVERSION=	0.3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Quotes strings as required for perl to eval them back correctly

BUILD_DEPENDS=	p5-Compress-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Text::Quote.3

.include <bsd.port.mk>
