# New ports collection makefile for:	www/p5-HTML-TableTiler
# Date created:				October 18th 2003
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-TableTiler
PORTVERSION=	1.13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	A Module generate a HTML table from bidimensional array data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/PullParser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::TableTiler.3

.include <bsd.port.mk>
