# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	misc devel
PKGNAMESUFFIX=	-libblkid

COMMENT=	Blkid library from e2fsprogs package

LICENSE=	LGPL20+
_no_license_file=	sorry

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

CONFIGURE_ARGS=	--enable-elf-shlibs --disable-libuuid --enable-libblkid

MASTERDIR=	${.CURDIR}/../../sysutils/e2fsprogs
MAKE_ARGS=	LIB_SUBDIRS=lib/blkid LDFLAGS_SHLIB=-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
ALL_TARGET=	libs
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install install-shlibs
INSTALL_WRKSRC=	${WRKSRC}/lib/blkid

PKGDIR=		${.CURDIR}

pre-build:
	${MKDIR} ${WRKSRC}/lib/blkid/elfshared
	cd ${WRKSRC}/util && ${MAKE_CMD} subst

post-build:
	cd ${INSTALL_WRKSRC} && ${MAKE_CMD} check

.include "${MASTERDIR}/Makefile"
