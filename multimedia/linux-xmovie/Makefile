# New ports collection makefile for:	xmovie
# Date created:		20 December 1998
# Whom:			MIHIRA Sanpei Yoshiro <sanpei@sanpei.org>
#
# $FreeBSD$
#

PORTNAME=	xmovie
PORTVERSION=	1.9.8.1
PORTREVISION=	1
CATEGORIES=	multimedia linux
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	heroines
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}.i386.rpm
EXTRACT_SUFX=

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A movie player for AVI, MPEG-2/4 and MOV movies

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
EXTRACT_CMD=	rpm2cpio
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS= | ${CPIO} -id --quiet
NO_BUILD=	yes
PLIST_FILES=	bin/xmovie
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/usr/bin

BRANDELF?=	/usr/bin/brandelf

# Linux binary should not be stripped by INSTALL_PROGRAM as it uses
# /usr/bin/strip which then brands the binary as a FreeBSD ELF one.
STRIP=

pre-install:
	@${BRANDELF} -t Linux ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
