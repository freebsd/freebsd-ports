# New ports collection makefile for:	e2fsprogs-libuuid
# Date created:				26 Jan 2006
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	misc devel
PKGNAMESUFFIX=	-libuuid

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	UUID library from e2fsprogs package

CONFIGURE_ARGS=	--enable-elf-shlibs --disable-fsck \
		--disable-e2initrd-helper --mandir=${MANPREFIX}/man

CONFLICTS=	ossp-uuid-[0-9]*

WITHOUT_NLS=	yes
MASTERDIR=	${.CURDIR}/../../sysutils/e2fsprogs
MAKE_ARGS=	LIB_SUBDIRS=lib/uuid
USE_LDCONFIG=	yes
ALL_TARGET=	libs
INSTALL_TARGET=	install install-shlibs
INSTALL_WRKSRC=	${WRKSRC}/lib/uuid

MAN3=		uuid.3 uuid_clear.3 uuid_compare.3 uuid_copy.3 uuid_generate.3 \
		uuid_is_null.3 uuid_parse.3 uuid_time.3 uuid_unparse.3 \
		uuid_generate_random.3 uuid_generate_time.3

PKGDIR=		${.CURDIR}

pre-build:
	${MKDIR} ${WRKSRC}/lib/uuid/elfshared

post-build:
	cd ${INSTALL_WRKSRC} && ${MAKE} check

.include "${MASTERDIR}/Makefile"
