# New ports collection makefile for:	p5-String-ShowDiff
# Date created:				April 26, 2003
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	String-ShowDiff
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	String
PKGNAMEPREFIX=	p5-

MAINTAINER=	m@absolight.net
COMMENT=	Perl extension to help visualize differences between strings

BUILD_DEPENDS=	${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		String::ShowDiff.3

.include <bsd.port.mk>
