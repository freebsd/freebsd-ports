# New ports collection makefile for:	p5-HTML-WikiConverter
# Date created:				2005/12/08
# Whom:	      				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-WikiConverter
PORTVERSION=	0.30
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	An HTML to wiki markup converter

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTML/Tree.pm:${PORTSDIR}/www/p5-HTML-Tree
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::WikiConverter.3 \
		HTML::WikiConverter::DocuWiki.3 \
		HTML::WikiConverter::Kwiki.3 \
		HTML::WikiConverter::MediaWiki.3 \
		HTML::WikiConverter::MoinMoin.3 \
		HTML::WikiConverter::Oddmuse.3 \
		HTML::WikiConverter::PhpWiki.3 \
		HTML::WikiConverter::PmWiki.3 \
		HTML::WikiConverter::SnipSnap.3 \
		HTML::WikiConverter::TikiWiki.3 \
		HTML::WikiConverter::UseMod.3 \
		HTML::WikiConverter::WakkaWiki.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		uses Unicode escapes and there requires perl 5.8.x or later
.endif

.include <bsd.port.post.mk>
