# Ports collection makefile for:  pear-Numbers_Words
# Date created:			  05 October 2005
# Whom:				  Piotr Rybicki (<meritus@innervision.pl>)
#
# $FreeBSD$
#

PORTNAME=	Numbers_Words
PORTVERSION=	0.16.2
CATEGORIES=	textproc pear

MAINTAINER=	meritus@innervision.pl
COMMENT=	PEAR package provides methods for spelling numerals in words

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Math/BigInteger.php:${PORTSDIR}/math/pear-Math_BigInteger
RUN_DEPENDS:=	${BUILD_DEPENDS}

CATEGORY=	Numbers
FILES=		Numbers/Words.php Numbers/Words/lang.bg.php \
		Numbers/Words/lang.cs.php Numbers/Words/lang.de.php \
		Numbers/Words/lang.dk.php Numbers/Words/lang.en_100.php \
		Numbers/Words/lang.en_GB.php Numbers/Words/lang.en_US.php \
		Numbers/Words/lang.es.php Numbers/Words/lang.es_AR.php \
		Numbers/Words/lang.et.php Numbers/Words/lang.fr.php \
		Numbers/Words/lang.fr_BE.php Numbers/Words/lang.he.php \
		Numbers/Words/lang.hu_HU.php Numbers/Words/lang.id.php \
		Numbers/Words/lang.it_IT.php Numbers/Words/lang.lt.php \
		Numbers/Words/lang.nl.php Numbers/Words/lang.pl.php \
		Numbers/Words/lang.pt_BR.php Numbers/Words/lang.ru.php \
		Numbers/Words/lang.sv.php
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
