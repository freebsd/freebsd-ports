# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	misc devel
PKGNAMESUFFIX=	-libblkid

COMMENT=	A blkid library from e2fsprogs package

LIB_DEPENDS=	libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFIGURE_ARGS=	--enable-elf-shlibs

MASTERDIR=	${.CURDIR}/../../sysutils/e2fsprogs
MAKE_ARGS=	LIB_SUBDIRS=lib/blkid
USES=		gmake
USE_LDCONFIG=	yes
ALL_TARGET=	libs
INSTALL_TARGET=	install install-shlibs
INSTALL_WRKSRC=	${WRKSRC}/lib/blkid

PKGDIR=		${.CURDIR}

pre-build:
	${MKDIR} ${WRKSRC}/lib/blkid/elfshared
	cd ${WRKSRC}/util && ${GMAKE} subst

post-build:
	cd ${WRKSRC}/lib/uuid && ${GMAKE}
	cd ${INSTALL_WRKSRC} && ${GMAKE} check

.include "${MASTERDIR}/Makefile"
