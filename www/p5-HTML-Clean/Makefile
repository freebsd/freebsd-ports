# New ports collection makefile for:	p5-HTML-Clean
# Date created:				March 30th 2001
# Whom:					Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-Clean
PORTVERSION=	0.8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	kapr@crosswinds.net

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLMAN1DIR=${MANPREFIX}/man/man1

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTML::Clean.3
MAN1=		htmlclean.1

.include <bsd.port.mk>
