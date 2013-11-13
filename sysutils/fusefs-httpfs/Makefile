# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	httpfs
PORTVERSION=	2.${VERSION}
PORTEPOCH=	1
CATEGORIES=	sysutils www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}2-${VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fuse-based http filesystem

WRKSRC=		${WRKDIR}/${PORTNAME}2-${VERSION}

VERSION=	0.1.5
USES=		fuse pkgconfig gmake
CFLAGS+=	-D__BSD_VISIBLE
ALL_TARGET=	httpfs2
PLIST_FILES=	bin/httpfs2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httpfs2 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
