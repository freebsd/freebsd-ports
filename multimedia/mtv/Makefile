# New ports collection makefile for:	mtv
# Date created:		30 Jan 2000
# Whom:			kris
#
# $FreeBSD$
#

PORTNAME=	mtv
PORTVERSION=	1.2.5
PORTREVISION=	2
CATEGORIES=	multimedia linux
MASTER_SITES=	ftp://ftp.mpegtv.com/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc/packages/TGZ/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz libSDLx11.so.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance MPEG video player (shareware)

EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz
NO_PACKAGE=	"No redistribution"
NO_CDROM=	"No redistribution"
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/mtv

MAN1=	mtv.1

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/mtv ${WRKSRC}/mtvp

do-install:
	@${MKDIR} ${WRKDIR}/libSDLx11
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/libSDLx11.so.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKDIR}/libSDLx11
	${INSTALL_DATA} ${WRKDIR}/libSDLx11/libSDLx11.so.0.9.9 \
		${LINUXBASE}/usr/X11R6/lib
	${LINUXBASE}/sbin/ldconfig
	${INSTALL_PROGRAM} ${WRKSRC}/mtv ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mtvp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mtv.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mtv
.for file in LICENSE README README-Fullscreen README-mtv-redhat \
	release-notes.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mtv
.endfor
.endif

.include <bsd.port.mk>
