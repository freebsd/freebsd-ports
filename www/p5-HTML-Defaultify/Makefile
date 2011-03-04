# New ports collection makefile for:	p5-HTML-Defaultify
# Date Created:				2009-02-10
# Whom:					takefu
#
# $FreeBSD$
#

PORTNAME=	HTML-Defaultify
PORTVERSION=	1.01
CATEGORIES=	www perl5
MASTER_SITES=	http://www.jmarshall.com/tools/defaultify/releases/\
		CPAN
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	akefu@airport.fm
COMMENT=	Perl module to populate HTML forms with default values

PERL_CONFIGURE=	yes

MAN3=		HTML::Defaultify.3

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser

.include <bsd.port.post.mk>
