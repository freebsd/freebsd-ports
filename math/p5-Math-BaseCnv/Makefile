# New ports collection makefile for:	Math-BaseCnv
# Date created:		3rd June, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Math-BaseCnv
PORTVERSION=	1.4.75
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}O6Pbr
EXTRACT_SUFX=	.tgz

MAINTAINER=	wenheping@gmail.com
COMMENT=	Fast functions to convert between number Bases

BUILD_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize

PERL_CONFIGURE=	yes

MAN3=		Math::BaseCnv.3

.include <bsd.port.mk>
