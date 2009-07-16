# New ports collection makefile for:	e2fsprogs-libblkid
# Date created:				2007-09-07
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#
# set PORTREVISION to avoid override by master port

PORTREVISION=	0
CATEGORIES=	misc devel
PKGNAMESUFFIX=	-libblkid

COMMENT=	A blkid library from e2fsprogs package

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFIGURE_ARGS=	--enable-elf-shlibs

WITHOUT_NLS=	yes
MASTERDIR=	${.CURDIR}/../../sysutils/e2fsprogs
MAKE_ARGS=	LIB_SUBDIRS=lib/blkid
USE_GMAKE=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	libs
INSTALL_TARGET=	install install-shlibs
INSTALL_WRKSRC=	${WRKSRC}/lib/blkid

MAN3=		libblkid.3

PKGDIR=		${.CURDIR}

pre-build:
	${MKDIR} ${WRKSRC}/lib/blkid/elfshared

post-build:
	cd ${WRKSRC}/lib/uuid && ${GMAKE}
	cd ${INSTALL_WRKSRC} && ${GMAKE} check

.include "${MASTERDIR}/Makefile"
