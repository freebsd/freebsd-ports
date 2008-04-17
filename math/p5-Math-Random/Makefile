# New ports collection makefile for:	Math::Random
# Date created:		5 Jul 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Math-Random
PORTVERSION=	0.69
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Random number generators

PERL_CONFIGURE=	yes

MAN3=		Math::Random.3

post-patch:
	@${RM} ${WRKSRC}/*.pl
	@${REINPLACE_CMD} -e '/test/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
