# New ports collection makefile for:	mtv
# Version required:	1.1.0.7
# Date created:		30 Jan 2000
# Whom:			kris
#
# $FreeBSD$
#

DISTNAME=	mtv-1.1.0.7
CATEGORIES=	graphics linux
MASTER_SITES=	ftp://ftp.mpegtv.com/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc/packages/TGZ/
DISTFILES=	mtv-1.1.0.7.tar.gz libforms.so.0.88.gz

MAINTAINER=	kris@FreeBSD.org

RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

EXTRACT_ONLY=	mtv-1.1.0.7.tar.gz
NO_PACKAGE=	"No redistribution"
NO_CDROM=	"No redistribution"
NO_BUILD=	yes
NO_FILTER_SHLIBS=yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/mtv

MAN1=	mtv.1

do-install:
	${GZIP_CMD} -dc ${DISTDIR}/libforms.so.0.88.gz > /compat/linux/usr/X11R6/lib/libforms.so.0.88
	/compat/linux/sbin/ldconfig
	${INSTALL_SCRIPT} ${WRKSRC}/mtv ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mtvp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mtv.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/mtv
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/mtv
	${INSTALL_DATA} ${WRKSRC}/release-notes.html ${PREFIX}/share/mtv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/mtv
	${INSTALL_DATA} ${WRKSRC}/README-Fullscreen ${PREFIX}/share/mtv
	${INSTALL_DATA} ${WRKSRC}/README-mtv-redhat ${PREFIX}/share/mtv

.include <bsd.port.mk>
