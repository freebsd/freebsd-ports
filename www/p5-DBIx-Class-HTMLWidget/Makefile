# New ports collection makefile for:	wwww/p5-DBIx-Class-HTMLWidget
# Date created:				1 Aug 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-HTMLWidget
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Like FromForm but with DBIx::Class and HTML::Widget

BUILD_DEPENDS=	p5-HTML-Widget>=1.10:${PORTSDIR}/www/p5-HTML-Widget \
		p5-DBIx-Class>=0.05:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::HTMLWidget.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
