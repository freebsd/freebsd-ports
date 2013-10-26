# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sendmail-Milter
PORTVERSION=	0.18
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	marc@pilgerer.org
COMMENT=	Module to write mail filters in Perl using sendmail's mail filter API

USES=		perl5
USE_PERL5=	configure

MAN3=		Sendmail::Milter.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if exists(${PERL5})
PERLTHREADS!=	${PERL5} -V:usethreads | ${AWK} '/define/ { print "define"; exit } END { exit 1 }' || ${ECHO_CMD}
.if ${PERLTHREADS} != "define"
IGNORE=	requires perl to be built with -DWITH_THREADS
.endif
.else
IGNORE=	requires an existing installation of perl, built with -DWITH_THREADS
.endif

.include <bsd.port.post.mk>
