# New ports collection makefile for:	Math-Bezier-Convert
# Date created:	   07 February 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Math-Bezier-Convert
PORTVERSION=	0.02
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert cubic and quadratic Bezier each other

PERL_CONFIGURE=	yes

MAN3=		Math::Bezier::Convert.3

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e 's/\x0d(?=\x0a)//'

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
