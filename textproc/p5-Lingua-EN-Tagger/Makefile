# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Lingua-EN-Tagger
PORTVERSION=	0.24
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Part-of-speech tagger for English natural language processing

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-HTML-Parser>=3.45:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Tagset>=3.20:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-Lingua-Stem>=0.81:${PORTSDIR}/textproc/p5-Lingua-Stem \
		p5-Memoize-ExpireLRU>=0.55:${PORTSDIR}/devel/p5-Memoize-ExpireLRU
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
