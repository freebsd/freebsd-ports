# New ports collection makefile for:	p5-HTML-FromANSI
# Date created:		2006-09-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-FromANSI
PORTVERSION=	2.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mark up ANSI sequences as HTML

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Term/VT102.pm:${PORTSDIR}/devel/p5-Term-VT102

PERL_CONFIGURE=	yes

MAN1=		ansi2html.1
MAN3=		HTML::FromANSI.3

.include <bsd.port.mk>
