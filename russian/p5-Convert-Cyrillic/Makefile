# New ports collection makefile for:	p5-Convert-Cyrillic
# Date created:				07 May 2009
# Whom:					Sergey Kandaurov <pluknet@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Convert-Cyrillic
PORTVERSION=	1.05
CATEGORIES=	russian converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	cyrillic-${PORTVERSION}

MAINTAINER=	pluknet@gmail.com
COMMENT=	Routines for converting from one cyrillic charset to another

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Unicode/Map8.pm:${PORTSDIR}/converters/p5-Unicode-Map8
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Convert::Cyrillic.3 \
		Lingua::DetectCharset.3

.include <bsd.port.mk>
