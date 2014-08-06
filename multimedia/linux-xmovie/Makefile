# Created by: MIHIRA Sanpei Yoshiro <sanpei@sanpei.org>
# $FreeBSD$

PORTNAME=	xmovie
PORTVERSION=	1.9.8
PORTREVISION=	4
CATEGORIES=	multimedia linux
MASTER_SITES=	SF/heroines/releases/021003
PKGNAMEPREFIX=	linux-

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Movie player for AVI, MPEG-2/4, and MOV movies

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_RPM=	yes
RPMVERSION=	1
USE_LINUX_APPS=	xorglibs
SRC_DISTFILES=	
LINUX_RPM_ARCH=	i386
NO_BUILD=	yes
PLIST_FILES=	usr/bin/xmovie
WRKSRC=		${WRKDIR}/usr/bin

pre-install:
	@${BRANDELF} -t Linux ${WRKSRC}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/usr/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/usr/bin/${PORTNAME}

.include <bsd.port.mk>
