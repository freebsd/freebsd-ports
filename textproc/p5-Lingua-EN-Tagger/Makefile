# New ports collection makefile for:    p5-Lingua-EN-Tagger
# Date created:				Tue Dec 30 16:56:56 CST 2003
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-Tagger
PORTVERSION=	0.16
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Part-of-speech tagger for English natural language processing

BUILD_DEPENDS=	${SITE_PERL}/Lingua/Stem/En.pm:${PORTSDIR}/textproc/p5-Lingua-Stem \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Memoize/ExpireLRU.pm:${PORTSDIR}/devel/p5-Memoize-ExpireLRU \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Lingua::EN::Tagger.3

.include <bsd.port.mk>
