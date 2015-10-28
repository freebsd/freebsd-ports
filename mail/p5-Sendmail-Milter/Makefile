# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sendmail-Milter
PORTVERSION=	0.18
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	marc@pilgerer.org
COMMENT=	Module to write mail filters in Perl using sendmail's mail filter API

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if exists(${PERL})
PERLTHREADS!=	${PERL} -V::usethreads
.if ${PERLTHREADS} != "'define';"
IGNORE=	requires perl to be built with -DWITH_THREADS
.endif
.endif

.include <bsd.port.post.mk>
