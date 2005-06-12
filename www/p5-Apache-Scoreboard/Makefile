# New ports collection makefile for:	Apache-Scoreboard
# Date Created:				08 Oct 2003
# Whom:					Trevor S. Cornpropst <tcornpropst@cox.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-Scoreboard
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	tcornpropst@cox.net
COMMENT=	Perl interface to the Apache scoreboard structure

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Apache::Scoreboard.3

INSTALLS_SHLIB=	YES

.include <bsd.port.mk>
