# New ports collection makefile for:	p5-IMDB-Movie
# Date created:		2003-11-04
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	IMDB-Movie
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JEFFA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to fetch movie info from www.imdb.com

DEPRECATED=	Removed from CPAN
EXPIRATION_DATE=	2012-04-25

BUILD_DEPENDS=	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IMDB::Movie.3

.include <bsd.port.mk>
