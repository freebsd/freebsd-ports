# New ports collection makefile for:	xmovie
# Date created:		20 December 1998
# Whom:			MIHIRA Sanpei Yoshiro <sanpei@sanpei.org>
#
# $FreeBSD$
#

PORTNAME=	xmovie
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	http://heroines.sourceforge.net/
DISTFILES=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}.i386.rpm

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A movie player for MPEG-2 and Quicktime movies

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	${LINUX_BASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		${LINUX_BASE}/usr/lib/libjpeg.so.62.0.0:${PORTSDIR}/graphics/linux-jpeg \
		${LINUX_BASE}/usr/lib/libpng.so.2.1.0.14:${PORTSDIR}/graphics/linux-png

ONLY_FOR_ARCHS=	i386
DOC_DIR=	${PREFIX}/share/doc/xmovie
EXTRACT_CMD=	rpm2cpio
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS= | cpio -id --quiet
LINUX_BASE=	/compat/linux
NO_BUILD=	yes
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes

# Linux binary should not be stripped by INSTALL_PROGRAM as it uses
# /usr/bin/strip which then brands the binary as a FreeBSD ELF one.
STRIP=

do-patch:
	@${DO_NADA}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/usr/local/bin/xmovie ${PREFIX}/bin
	@brandelf -t Linux ${PREFIX}/bin/xmovie
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOC_DIR}
	@${INSTALL_DATA} ${WRKSRC}/usr/doc/xmovie-${PORTVERSION:R}/README ${DOC_DIR}/README
	@${INSTALL_DATA} ${WRKSRC}/usr/doc/xmovie-${PORTVERSION:R}/index.html ${DOC_DIR}/index.html
.endif
.include <bsd.port.mk>
