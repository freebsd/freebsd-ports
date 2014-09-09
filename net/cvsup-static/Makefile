# Created by: Xin Li <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvsup-static
PORTVERSION=	16.1h
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	delphij
PKGNAMEPREFIX=	binary-
DISTNAME=	cvsup-without-gui-static-${ARCH}-${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	File distribution system optimized for CVS

ONLY_FOR_ARCHS=	amd64

DISTINFO_FILE=	${.CURDIR}/distinfo.${ARCH}

NO_BUILD=	yes
USES=		tar:xz

do-install:
	(cd ${WRKDIR} && ${COPYTREE_BIN} bin ${STAGEDIR}${PREFIX})
	(cd ${WRKDIR} && ${COPYTREE_BIN} sbin ${STAGEDIR}${PREFIX})
	(cd ${WRKDIR} && ${COPYTREE_SHARE} share/cvsup ${STAGEDIR}${PREFIX})
	(cd ${WRKDIR} && ${COPYTREE_SHARE} man ${STAGEDIR}${PREFIX})

.include <bsd.port.mk>
