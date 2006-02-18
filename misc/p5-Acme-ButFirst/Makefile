# New ports collection makefile for:	Acme-ButFirst
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Acme-ButFirst
PORTVERSION=	1.00
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Acme
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Do something, but first do something else

MAN3=	Acme::ButFirst.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl5.6
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Filter/Simple.pm:${PORTSDIR}/textproc/p5-Filter-Simple
.endif

.include <bsd.port.post.mk>
