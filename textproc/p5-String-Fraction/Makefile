# New ports collection makefile for:	String-Fraction
# Date created:				16 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	String-Fraction
PORTVERSION=	0.30
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Convert fractions into Unicode chars

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Fraction>=0.40:${PORTSDIR}/textproc/p5-HTML-Fraction
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	String::Fraction.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
