# New ports collection makefile for:	p5-Date-Handler
# Date Created:				25 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#
# Considering this module for calculating date, so
# I putted it into 'math' and not 'devel' or other

PORTNAME=	Date-Handler
PORTVERSION=	0.19
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	shell@shellhung.org

PERL_CONFIGURE=	yes

MAN3=		Date::Handler.3 Date::Handler::Delta.3 \
		Date::Handler::Range.3 Date::Handler::Test.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
