# Ports collection makefile for:  pear-Numbers_Words
# Date created:			  05 October 2005
# Whom:				  Piotr Rybicki (<meritus@innervision.pl>)
#
# $FreeBSD$
#

PORTNAME=	Numbers_Words
PORTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	textproc pear

MAINTAINER=	meritus@innervision.pl
COMMENT=	PEAR package provides methods for spelling numerals in words

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Numbers
FILES=		Words.php Words/lang.bg.php Words/lang.cs.php \
		Words/lang.de.php Words/lang.dk.php Words/lang.en_100.php \
		Words/lang.en_GB.php Words/lang.en_US.php Words/lang.es.php \
		Words/lang.es_AR.php Words/lang.et.php Words/lang.fr.php \
		Words/lang.fr_BE.php Words/lang.he.php Words/lang.hu_HU.php \
		Words/lang.id.php Words/lang.it_IT.php Words/lang.lt.php \
		Words/lang.nl.php Words/lang.pl.php Words/lang.pt_BR.php \
		Words/lang.ru.php Words/lang.sv.php
TESTS=		AllTests.php BulgarianTest.php \
		English100Test.php EnglishGbTest.php \
		EnglishUsTest.php FrenchBeTest.php \
		FrenchTest.php GermanTest.php \
		ItalianTest.php PolishTest.php \
		PortugueseBrazilianTest.php SpanishTest.php \
		test-numbers-words.php
DOCS=		ChangeLog README
_DOCSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
