# New ports collection makefile for:   snowflake
# Date created:        29 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snowflake
PORTVERSION=	0.01a
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A snowflake image generator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

PLIST_FILES=	bin/snowflake
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
MAKE_ARGS=	CC="${CC} ${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snowflake ${PREFIX}/bin

.include <bsd.port.mk>
