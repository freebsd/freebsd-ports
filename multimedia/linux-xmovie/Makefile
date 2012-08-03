# New ports collection makefile for:	xmovie
# Date created:		20 December 1998
# Whom:			MIHIRA Sanpei Yoshiro <sanpei@sanpei.org>
#
# $FreeBSD$
#

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

EXTRACT_DEPENDS=rpm2cpio:${PORTSDIR}/archivers/rpm

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
EXTRACT_CMD=	rpm2cpio
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS= | ${CPIO} -id --quiet
NO_BUILD=	yes
PLIST_FILES=	bin/xmovie
WRKSRC=		${WRKDIR}/usr/bin

pre-install:
	@${BRANDELF} -t Linux ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
