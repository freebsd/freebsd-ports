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

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/snowflake ${PREFIX}/bin

.include <bsd.port.mk>
