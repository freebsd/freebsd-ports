# New ports collection makefile for:	divx4linux
# Date created:				Mon Sep 24 15:40:14 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	divx4linux
PORTVERSION=	0.${RELEASE_DATE:S/_/./}
CATEGORIES=	multimedia linux
MASTER_SITES=	http://download.divx.com/videocodecs/linux/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${RELEASE_DATE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Linux binary release of DivX 4 (TM) Codec

RESTRICTED=	unsure of licensing issues

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
WRKSRC=	${WRKDIR}/${DISTNAME:C/_.+$//}
NO_BUILD=	yes
NO_LATEST_LINK=	yes
PLIST_SUB=	PKGNAME="${PKGNAME}"

RELEASE_DATE=	20011010_4.02

PKGDEINSTALL=	${PKGINSTALL}

post-patch:
.for ext in h linux txt
	@${REINPLACE_CMD} -e "s///" ${WRKSRC}/*.${ext}
.endfor

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/usr/doc/${PKGNAME}
.for ext in linux txt
	@${INSTALL_DATA} ${WRKSRC}/*.${ext} ${PREFIX}/usr/doc/${PKGNAME}
.endfor
.endif
# Header file installation
	@${MKDIR} ${PREFIX}/usr/include/divx4
	@${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/usr/include/divx4
	@${MKDIR} ${PREFIX}/usr/lib/divx4
	@${INSTALL_DATA} ${WRKSRC}/*.so ${PREFIX}/usr/lib/divx4
	@${LINUXBASE}/sbin/ldconfig

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
