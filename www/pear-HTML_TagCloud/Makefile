# Ports collection makefile for:  pear-HTML_TagCloud
# Date created:			  08 April 2008
# Whom:				  Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML_TagCloud
PORTVERSION=	0.2.3
CATEGORIES=	www devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Generate TagCloud in HTML And Visualize Tags

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	HTML
FILES=		TagCloud.php

DOCS=		examples/TagCloud_example1.php \
		examples/TagCloud_example2.php \
		examples/TagCloud_example3.php \
		examples/TagCloud_example4.php

TESTS=		AllTests.php TagCloudTest.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
