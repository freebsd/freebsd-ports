# Created by: Joris Vandalon
# $FreeBSD$

PORTNAME=	rar2fs
PORTVERSION=	1.29.3
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	n_carlsson@outlook.com
COMMENT=	Mount RAR archives as file system

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${NONEXISTENT}:${LIBUNRAR_PORT}:patch
LIB_DEPENDS=	libunrar.so.6:${LIBUNRAR_PORT}

USES=		autoreconf compiler:c11 gmake fuse
USE_GITHUB=	yes
GH_ACCOUNT=	hasse69

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static-unrar \
		--with-fuse-lib=${LOCALBASE}/lib \
		--with-fuse=${LOCALBASE}/include/fuse \
		--with-unrar=`${MAKE} -C ${PORTSDIR}/${LIBUNRAR_PORT} -VWRKSRC` \
		--with-unrar-lib=${LOCALBASE}/lib
CONFIGURE_ENV=	LIBUNRAR_PKG=${LIBUNRAR_PKG}

PLIST_FILES=	bin/${PORTNAME} \
		bin/mkr2i \
		man/man1/rar2fs.1.gz

LIBUNRAR_PORT=	archivers/libunrar6
LIBUNRAR_PKG=	${LIBUNRAR_PORT:S|archivers/||}

.include <bsd.port.mk>
