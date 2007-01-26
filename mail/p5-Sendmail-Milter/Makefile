# New ports collection makefile for:	Sendmail::Milter
# Date created:				25 March 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sendmail-Milter
PORTVERSION=	0.18
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Sendmail
PKGNAMEPREFIX=	p5-

MAINTAINER=	marc@pilgerer.org
COMMENT=	Module to write mail filters in Perl using sendmail's mail filter API

PERL_CONFIGURE=	yes

MAN3=		Sendmail::Milter.3

.include <bsd.port.pre.mk>

.if exists(${PERL5})
PERLTHREADS!=	${PERL5} -V:usethreads | ${AWK} '/define/ { print "define"; exit }'
.if ${PERLTHREADS} != "define"
IGNORE=	requires perl to be built with -DWITH_THREADS
.endif
.else
IGNORE=	requires an existing installation of perl, built with -DWITH_THREADS
.endif

.include <bsd.port.post.mk>
