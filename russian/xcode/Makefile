# New ports collection makefile for:	xcode
# Version required:	1.0
# Date created:		13 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

DISTNAME=	xcode
PKGNAME=	xcode-1.0
CATEGORIES=	russian
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/util/text/

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xcode ${PREFIX}/bin

.include <bsd.port.mk>
