# New ports collection makefile for:	p5-HTML-FromANSI
# Date created:		2006-09-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-FromANSI
PORTVERSION=	1.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Mark up ANSI sequences as HTML

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Term/VT102.pm:${PORTSDIR}/devel/p5-Term-VT102

PERL_CONFIGURE=	yes

MAN1=		ansi2html.1
MAN3=		HTML::FromANSI.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601 # from p5-HTML-Parser
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
