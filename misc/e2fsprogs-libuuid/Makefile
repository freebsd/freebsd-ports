# New ports collection makefile for:	e2fsprogs-libuuid
# Date created:				26 Jan 2006
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	misc devel
PKGNAMESUFFIX=	-libuuid

COMMENT=	UUID library from e2fsprogs package

CONFLICTS=	ossp-uuid-[0-9]*

CONFIGURE_ARGS=	--enable-elf-shlibs

WITHOUT_NLS=	yes
MASTERDIR=	${.CURDIR}/../../sysutils/e2fsprogs
MAKE_ARGS=	LIB_SUBDIRS=lib/uuid
USE_LDCONFIG=	yes
ALL_TARGET=	libs
INSTALL_TARGET=	install install-shlibs
INSTALL_WRKSRC=	${WRKSRC}/lib/uuid
FILESDIR=	${.CURDIR}/files
USE_RC_SUBR=	uuidd

MAN1=		uuidgen.1

MAN3=		uuid.3 uuid_clear.3 uuid_compare.3 uuid_copy.3 uuid_generate.3 \
		uuid_is_null.3 uuid_parse.3 uuid_time.3 uuid_unparse.3 \
		uuid_generate_random.3 uuid_generate_time.3

MAN8=		uuidd.8

PKGDIR=		${.CURDIR}

post-patch::
	${REINPLACE_CMD} -e 's,/var/lib/libuuid,/var/run/libuuid,g' \
	    -e 's,/usr/sbin/uuidd,${PREFIX}/sbin/uuidd,' \
	    ${WRKSRC}/lib/uuid/*.[ch]

pre-build:
	${MKDIR} ${WRKSRC}/lib/uuid/elfshared

# ulimit guards against runaway tests
# failure to launch uuidd is fine (one might be running, or we may lack
# privileges); if it works, it'll quit after 50 seconds
post-build:
	cd ${WRKSRC}/misc && ${MAKE} uuidgen uuidgen.1 uuidd uuidd.8
	( ulimit -t 5 ; cd ${INSTALL_WRKSRC} && { ../../misc/uuidd -T50 || true ; ${MAKE} check ; } )

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/misc/uuidgen ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/misc/uuidgen.1 ${MAN8PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/misc/uuidd ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/misc/uuidd.8 ${MAN8PREFIX}/man/man8/
	${MKDIR} /var/run/libuuid

.include "${MASTERDIR}/Makefile"
