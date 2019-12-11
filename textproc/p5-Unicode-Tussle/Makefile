# $FreeBSD$

PORTNAME=	Unicode-Tussle
PORTVERSION=	1.111
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Tom's Unicode Scripts So Life is Easier

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Lingua-EN-Syllable>=0:textproc/p5-Lingua-EN-Syllable \
		p5-Lingua-JA-Romanize-Japanese>=0:japanese/p5-Lingua-JA-Romanize-Japanese \
		p5-Lingua-KO-Hangul-Util>=0:korean/p5-Lingua-KO-Hangul-Util \
		p5-Lingua-KO-Romanize-Hangul>=0:korean/p5-Lingua-KO-Romanize-Hangul \
		p5-Lingua-ZH-Romanize-Pinyin>=0:chinese/p5-Lingua-ZH-Romanize-Pinyin \
		p5-Unicode-LineBreak>=0:textproc/p5-Unicode-LineBreak \
		p5-Unicode-Unihan>=0:textproc/p5-Unicode-Unihan

USES=		perl5 shebangfix
USE_PERL5=	configure
NO_ARCH=	yes

SHEBANG_FILES=	script/*

post-patch:
	cd ${WRKSRC}/script && ${RM} es-sort hantest havshpx hypertest vowel-sigs nunez

.include <bsd.port.mk>
