# New ports collection makefile for:	wwww/p5-DBIx-Class-HTMLWidget
# Date created:				1 Aug 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-HTMLWidget
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Like FromForm but with DBIx::Class and HTML::Widget

RUN_DEPENDS=	p5-HTML-Widget>=1.10:${PORTSDIR}/www/p5-HTML-Widget \
		p5-DBIx-Class>=0.05:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	DBIx::Class::HTMLWidget.3

.include <bsd.port.mk>
