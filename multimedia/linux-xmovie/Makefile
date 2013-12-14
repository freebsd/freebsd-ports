# Created by: MIHIRA Sanpei Yoshiro <sanpei@sanpei.org>
# $FreeBSD$

PORTNAME=	xmovie
PORTVERSION=	1.9.8.1
PORTREVISION=	3
CATEGORIES=	multimedia linux
MASTER_SITES=	SF/heroines/releases/021003
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}.i386.rpm
EXTRACT_SUFX=

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Movie player for AVI, MPEG-2/4, and MOV movies

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
EXTRACT_CMD=	${TAR} -xf
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=
NO_BUILD=	yes
PLIST_FILES=	bin/xmovie
WRKSRC=		${WRKDIR}/usr/bin

pre-install:
	@${BRANDELF} -t Linux ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
