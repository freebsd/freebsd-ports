# New ports collection makefile for:	p5-WWW-AtMovies-TV
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	WWW-AtMovies-TV
PORTVERSION=	0.04
DISTVERSIONPREFIX=v
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/A/AL/ALEC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve TV information from http://www.atmovies.com.tw/

RUN_DEPENDS=	p5-HTML-TableExtract>=2.1:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-Moose>=0.55:${PORTSDIR}/devel/p5-Moose \
		p5-WWW-Mechanize>=1.34:${PORTSDIR}/www/p5-WWW-Mechanize
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::AtMovies::TV.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-version>=0.76:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
