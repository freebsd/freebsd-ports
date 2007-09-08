# New ports collection makefile for:	p5-Sudo
# Date created:		2007-05-27
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Sudo
PORTVERSION=	0.32
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/L/LA/LANDMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for running a command line sudo

RUN_DEPENDS=	${SITE_PERL}/Term/ReadPassword.pm:${PORTSDIR}/devel/p5-Term-ReadPassword \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run

PERL_CONFIGURE=	5.8.1+

MAN3=		Sudo.3

.include <bsd.port.mk>
