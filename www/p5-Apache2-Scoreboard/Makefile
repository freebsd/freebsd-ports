# New ports collection makefile for:	Apache2-Scoreboard
# Date Created:				11 June 2005
# Whom:					Philip Paeps <philip@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache2-Scoreboard
PORTVERSION=	2.06
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Apache
DISTNAME=	Apache-Scoreboard-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Perl interface to the Apache scoreboard structure

BROKEN=		Broken due the new mod_perl2 API
BUILD_DEPENDS=	${LOCALBASE}/libexec/apache2/mod_perl.so:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Apache::Scoreboard.3

INSTALLS_SHLIB=	YES

.include <bsd.port.mk>
