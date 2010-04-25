# Ports collection makefile for:  pear-File_Fortune
# Date created:			  12 July 2007
# Whom:				  Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	File_Fortune
PORTVERSION=	1.0.0
CATEGORIES=	textproc pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interface for reading from and writing to fortune files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	File
FILES=		Fortune.php Fortune/Exception.php
_FILESDIR=	File
TESTS=		AllTests.php File_FortuneTest.php orig/ftest orig/ftest.dat \
		orig/ftest2 orig/ftest2.dat
EXAMPLES=	phpFortune
DOCS=		File_Fortune.cls
_DOCSDIR=	tutorials

post-extract:
	${MV} ${WRKSRC}/File/Fortune.php ${WRKSRC}/File/Fortune ${WRKSRC}
	${MV} ${WRKSRC}/tests/_files/orig ${WRKSRC}/tests/orig

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
