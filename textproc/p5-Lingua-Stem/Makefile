# Created by: Thorsten Greiner <thorsten.greiner@web.de>
# $FreeBSD$

PORTNAME=		Lingua-Stem
PORTVERSION=		0.84
CATEGORIES=		textproc perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	CPAN:SNOWHARE
PKGNAMEPREFIX=		p5-

MAINTAINER=		perl@FreeBSD.org
COMMENT=		Provides word stemming algorithms localized by language

BUILD_DEPENDS=		p5-Lingua-PT-Stemmer>=0:${PORTSDIR}/textproc/p5-Lingua-PT-Stemmer \
			p5-Lingua-Stem-Fr>=0:${PORTSDIR}/textproc/p5-Lingua-Stem-Fr \
			p5-Lingua-Stem-It>=0:${PORTSDIR}/textproc/p5-Lingua-Stem-It \
			p5-Lingua-Stem-Ru>=0:${PORTSDIR}/textproc/p5-Lingua-Stem-Ru \
			p5-Lingua-Stem-Snowball-Da>=0:${PORTSDIR}/textproc/p5-Lingua-Stem-Snowball-Da \
			p5-Lingua-Stem-Snowball-No>=0:${PORTSDIR}/textproc/p5-Lingua-Stem-Snowball-No \
			p5-Lingua-Stem-Snowball-Se>=0:${PORTSDIR}/textproc/p5-Lingua-Stem-Snowball-Se \
			p5-Text-German>=0:${PORTSDIR}/textproc/p5-Text-German
RUN_DEPENDS:=		${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=			Lingua::Stem.3 Lingua::Stem::AutoLoader.3 \
			Lingua::Stem::En.3 Lingua::Stem::Pt.3 \
			Lingua::Stem::EnBroken.3 Lingua::Stem::Gl.3 \
			Lingua::Stem::No.3 Lingua::Stem::De.3 \
			Lingua::Stem::Sv.3 Lingua::Stem::Da.3

.include <bsd.port.mk>
