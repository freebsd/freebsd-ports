# New ports collection makefile for:	Math-Bezier-Convert
# Date created:	   07 February 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Math-Bezier-Convert
PORTVERSION=	0.02
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/Y/YS/YSAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Convert cubic and quadratic bezier each other

PERL_CONFIGURE=	yes

MAN3=		Math::Bezier::Convert.3

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e 's/\x0d(?=\x0a)//'

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
