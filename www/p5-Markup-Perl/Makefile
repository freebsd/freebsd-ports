# New ports collection makefile for:	p5-Markup-Perl
# Date created:				1 September 2008
# Whom:	      				Jeremy Chadwick <koitsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Markup-Perl
PORTVERSION=	0.5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MM/MMATHEWS
PKGNAMEPREFIX=	p5-
DISTNAME=	Markup-Perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support perl code inside CGI scripts using simple tags

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=		Markup::Perl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS=	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
.endif

.include <bsd.port.post.mk>
