# Created by: Joris Vandalon
# $FreeBSD$

PORTNAME=	rar2fs
PORTVERSION=	1.23.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Mount rar archives as filesystem

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libunrar.so.5:${LIBUNRAR_PORT}
BUILD_DEPENDS=	${NONEXISTENT}:${LIBUNRAR_PORT}:patch

USE_GITHUB=	yes
GH_ACCOUNT=	hasse69

USES=		autoreconf execinfo gmake fuse

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fuse-lib=${LOCALBASE}/lib \
		--with-fuse=${LOCALBASE}/include/fuse \
		--with-unrar=`${MAKE} -C ${PORTSDIR}/${LIBUNRAR_PORT} -VWRKSRC` \
		--with-unrar-lib=${LOCALBASE}/lib
CONFIGURE_ENV=	LIBUNRAR_PKG=${LIBUNRAR_PKG}

PLIST_FILES=	bin/${PORTNAME} \
		bin/mkr2i \
		man/man1/rar2fs.1.gz

LIBUNRAR_PORT=	archivers/libunrar5
LIBUNRAR_PKG=	${LIBUNRAR_PORT:S|archivers/||}

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g' -e '/rar2fs_LINK =/s|CC|CXX|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
