# Ports collection makefile for:  pear-File
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	File
PORTVERSION=	1.4.0
PORTEPOCH=	2
CATEGORIES=	sysutils www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR common file and directory routines

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PHP=	pcre

FILES=		File.php
_TESTSDIR=	tests/File
TESTS=		close.phpt \
		locking.phpt \
		read.phpt \
		readAll.phpt \
		readChar.phpt \
		readLine.phpt \
		rewind.phpt \
		setup.inc.php \
		teardown.inc.php \
		write.phpt \
		writeChar.phpt \
		writeLine.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
