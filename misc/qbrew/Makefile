# New ports collection makefile for:	qbrew
# Date created:				22 September 2000
# Whom:					David Johnson <david@usermode.org>
#
# $FreeBSD$
#

PORTNAME=	qbrew
PORTVERSION=	0.3.3
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	david@usermode.org
COMMENT=	A homebrewer's recipe calculator

GNU_CONFIGURE=	yes
USE_QT_VER=	3

post-install:
	${STRIP_CMD} ${PREFIX}/bin/qbrew

.include <bsd.port.mk>
