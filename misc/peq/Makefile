# New ports collection makefile for:	peq
# Date created:				2 April 1999
# Whom:					Gordon Greeff
#
# $FreeBSD$
#

PORTNAME=	peq
PORTVERSION=	0.7.1
CATEGORIES=	misc games
MASTER_SITES=	http://www.shrubbery.org.za/peq/
# Fortunecity.com doesn't allow linking from external sites.
# Please look at the WWW site in pkg-descr for more information - edwin 20021227

MAINTAINER=	gordon@shrubbery.org.za
COMMENT=	Fortune like program

USE_GCC=	2.95
USE_QT_VER=	1

post-install:
	${STRIP_CMD} ${PREFIX}/bin/peq
	${STRIP_CMD} ${PREFIX}/bin/xpeq

.include <bsd.port.mk>
