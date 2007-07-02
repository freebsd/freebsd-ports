# New ports collection makefile for:	p5-Sudo
# Date created:		2007-05-27
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Sudo
PORTVERSION=	0.31
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/L/LA/LANDMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl extension for running a command line sudo

RUN_DEPENDS=	${SITE_PERL}/Term/ReadPassword.pm:${PORTSDIR}/devel/p5-Term-ReadPassword \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Sudo.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
IGNORE=		requires Perl >= 5.8.1. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
