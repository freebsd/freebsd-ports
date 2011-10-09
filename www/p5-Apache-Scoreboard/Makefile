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
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to the Apache scoreboard structure

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	depends on mod_perl
EXPIRATION_DATE=	2011-11-01

PORTSCOUT=	limit:^0

CFLAGS+=	-I${LOCALBASE}/include

PERL_CONFIGURE=	YES

MAN3=		Apache::Scoreboard.3

USE_LDCONFIG=	YES

.include <bsd.port.mk>
