# New ports collection makefile for:	divx4linux
# Date created:				Mon Sep 24 15:40:14 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	divx4linux
PORTVERSION=	5.0.${RELEASE_DATE}
CATEGORIES=	multimedia linux
MASTER_SITES=	http://download.divx.com/divx/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}501-${RELEASE_DATE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org

RESTRICTED=	unsure of licensing issues

ONLY_FOR_ARCHS=	i386
USE_REINPLACE=	yes
USE_LINUX_PREFIX=	yes
WRKSRC=	${WRKDIR}/${DISTNAME:S/501-/-/}
NO_BUILD=	yes
PLIST_SUB=	PKGNAME="${PKGNAME}"

DOC_EXT=	htm linux txt
RELEASE_DATE=	20020418

post-patch:
.for ext in ${DOC_EXT}
	@${REINPLACE_CMD} -e "s///" ${WRKSRC}/*.${ext}
.endfor

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/usr/doc/${PKGNAME}
.for ext in ${DOC_EXT}
	@${INSTALL_DATA} ${WRKSRC}/*.${ext} ${PREFIX}/usr/doc/${PKGNAME}
.endfor
.endif
# Header file installation
	@${MKDIR} ${PREFIX}/usr/include/divx
	@${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/usr/include/divx
# Library installation
	@${INSTALL_DATA} ${WRKSRC}/*.so ${PREFIX}/usr/lib
	@${LINUXBASE}/sbin/ldconfig

.include <bsd.port.mk>
