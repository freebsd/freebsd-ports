# New ports collection makefile for:	p5-Net-CSTA
# Date created:		2006-07-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-CSTA
PORTVERSION=	0.04
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for ECMA CSTA

RUN_DEPENDS=	${SITE_PERL}/Convert/ASN1.pm:${PORTSDIR}/converters/p5-Convert-ASN1 \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple

PERL_CONFIGURE=	yes

MAN3=		Net::CSTA.3

.include <bsd.port.mk>
