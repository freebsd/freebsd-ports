# Ports collection makefile for:  pear-Mail_Mime
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail_Mime
PORTVERSION=	1.5.2
PORTEPOCH=	1
CATEGORIES=	mail www pear
DISTNAME=	Mail_Mime-1.5.1

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	PEAR classes to create and decode MIME messages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Mail
FILES=		mime.php mimePart.php
DATA=		xmail.dtd xmail.xsl
_DATADIR=	.
SCRIPTFILES=	phail.php
TESTS=		class-filename.phpt encoding_case.phpt sleep_wakeup_EOL-bug3488-part1.phpt \
		sleep_wakeup_EOL-bug3488-part2.phpt tabs_quoted_printable.phpt \
		test_Bug_30_1.phpt test_Bug_30_2.phpt test_Bug_30_3.phpt test_Bug_30_4.phpt \
		test_Bug_3513_1.phpt test_Bug_3513_2.phpt test_Bug_3513_3.phpt \
		test_Bug_7561_1.phpt test_Bug_8223_1.phpt test_Bug_8386_1.phpt \
		test_Bug_8541_1.phpt test_Bug_9558_1.phpt test_Bug_9722_1.phpt \
		test_Bug_9725_1.phpt test_Bug_9976_1.phpt test_Bug_10298_1.phpt \
		test_Bug_10596_1.phpt test_Bug_10816_1.phpt

post-extract:
	${MV} ${WRKSRC}/scripts/phail.php ${WRKSRC}/pear-phail.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
