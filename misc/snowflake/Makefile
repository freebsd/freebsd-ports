# New ports collection makefile for:   snowflake
# Version required:    0.01a
# Date created:        29 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	snowflake
PKGNAME=	snowflake-0.01a
CATEGORIES=	misc
MASTER_SITES=	http://www.infomatch.com/~donaldj/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/snowflake ${PREFIX}/bin

.include <bsd.port.mk>
