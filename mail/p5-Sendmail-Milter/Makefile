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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A module to write mail filters in Perl using sendmail's mail filter API

IGNORE=		"Requires perl compiled manually with threads."

PERL_CONFIGURE=	yes
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Sendmail::Milter.3

.include <bsd.port.mk>
