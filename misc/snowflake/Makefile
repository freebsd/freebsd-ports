# New ports collection makefile for:   snowflake
# Date created:        29 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snowflake
PORTVERSION=	0.01a
CATEGORIES=	misc
MASTER_SITES=	http://www.infomatch.com/~donaldj/
DISTNAME=	${PORTNAME}

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_GTK=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/snowflake ${PREFIX}/bin

.include <bsd.port.mk>
