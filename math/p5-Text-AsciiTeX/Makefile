# New ports collection makefile for:	p5-Text-AsciiTex
# Date created:		2012-02-04
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-AsciiTeX
PORTVERSION=	0.04
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert (La)TeX formulas to ASCII art

BUILD_DEPENDS=	p5-ExtUtils-CBuilder>=0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
RUN_DEPENDS=	p5-parent>=0:${PORTSDIR}/devel/p5-parent

PERL_MODBUILD=	yes

MAN3=	Text::AsciiTeX.3 Text::AsciiTeX::Syntax.3

.include <bsd.port.mk>
