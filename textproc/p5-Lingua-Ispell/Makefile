# New ports collection makefile for:    p5-Lingua-Ispell
# Date created:                         15 March 2001
# Whom:                                 -
#
# $FreeBSD$

PORTNAME=		Lingua-Ispell
PORTVERSION=		0.07
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=		p5-

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A Perl module that encapsulates access to the Ispell program.

BUILD_DEPENDS=		${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell

PERL_CONFIGURE=		YES

MAN3=			Lingua::Ispell.3

MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
