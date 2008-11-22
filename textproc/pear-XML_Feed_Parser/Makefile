# Ports collection makefile for:  pear-XML_Feed_Parser
# Date created:			  2007/05/01
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML_Feed_Parser
PORTVERSION=	1.0.3
CATEGORIES=	textproc devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Providing a unified API for handling Atom/RSS

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	tidy dom

CATEGORY=	XML/Feed
FILES=		Parser.php Parser/Atom.php Parser/AtomElement.php \
		Parser/Exception.php \
		Parser/RSS09.php Parser/RSS09Element.php Parser/RSS1.php \
		Parser/RSS11.php Parser/RSS11Element.php Parser/RSS1Element.php \
		Parser/RSS2.php Parser/RSS2Element.php Parser/Type.php \
		samples/atom10-entryonly.xml samples/atom10-example1.xml \
		samples/atom10-example2.xml samples/delicious.feed \
		samples/flickr.feed samples/grwifi-atom.xml samples/hoder.xml \
		samples/illformed_atom10.xml samples/rss091-complete.xml \
		samples/rss091-international.xml samples/rss091-simple.xml \
		samples/rss092-sample.xml samples/rss10-example1.xml \
		samples/rss10-example2.xml samples/rss2sample.xml \
		samples/sixapart-jp.xml samples/technorati.feed schemas/atom.rnc \
		schemas/rss10.rnc schemas/rss11.rnc
TESTS=		XML_Feed_Parser_TestCase.php accessTypes.php atomCompliance.php \
		atomEntryOnly.php atomValues.php convert-tests.php errors.php \
		farsi.php iteration.php japanese.php rss091Values.php \
		rss092Values.php rss1Values.php rss2Values.php tidy.php \
		convertedtests/amp.php convertedtests/atom.php \
		convertedtests/atom10.php convertedtests/base.php \
		convertedtests/cdf.php convertedtests/date.php  \
		convertedtests/encoding.php convertedtests/feedburner.php \
		convertedtests/http.php convertedtests/itunes.php \
		convertedtests/lang.php convertedtests/namespace.php \
		convertedtests/rdf.php convertedtests/rss.php \
		convertedtests/sanitize.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
