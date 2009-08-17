# New ports collection makefile for:	p5-REST-Google
# Date created:				01 May 2008
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	REST-Google
PORTVERSION=	1.0.7
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/E/EJ/EJS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Access Google REST (aka AJAX) API from Perl

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
    		p5-version>=0.50:${PORTSDIR}/devel/p5-version \
    		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
    		p5-Class-Data-Inheritable>0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-JSON-Any>=1.16:${PORTSDIR}/converters/p5-JSON-Any
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PERL5=	5.6.1+
PERL_MODBUILD=	yes

MAN3=	REST::Google.3 \
	REST::Google::Feeds.3 \
	REST::Google::Search.3 \
	REST::Google::Search::Blogs.3 \
	REST::Google::Search::Books.3 \
	REST::Google::Search::Images.3 \
	REST::Google::Search::Local.3 \
	REST::Google::Search::News.3 \
	REST::Google::Search::Patent.3 \
	REST::Google::Search::Video.3 \
	REST::Google::Search::Web.3 \
	REST::Google::Translate.3

.include <bsd.port.mk>
