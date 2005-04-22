# New ports collection makefile for:	samba-libsmbclient
# Date created:				23 Juli 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTREVISION=		2
PORTEPOCH=		0
PKGNAMESUFFIX=		-libsmbclient

COMMENT=		The shared lib from the samba packages

CONFLICTS=

SAMBA_PORT=		samba3
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
PKGDIR=			${.CURDIR}

INSTALLS_SHLIB=		yes

# We WANT libsmbclient support :)
CONFIGURE_ARGS+=	--with-libsmbclient
# This is taken from SAMBA_PORT(grep without)
CONFIGURE_ARGS+=	--disable-cups
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-syslog
CONFIGURE_ARGS+=	--without-quotas
CONFIGURE_ARGS+=	--without-utmp
CONFIGURE_ARGS+=	--without-winbind
CONFIGURE_ARGS+=	--without-ldapsam
CONFIGURE_ARGS+=	--without-pam_smbpass

do-build:
	cd ${WRKSRC} && ${MAKE} proto
	cd ${WRKSRC} && ${MAKE} libsmbclient

do-install:
	-@${MKDIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/libsmbclient.h ${PREFIX}/include
	-@${MKDIR} ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/libsmbclient.a ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/libsmbclient.so.0 ${PREFIX}/lib
	${LN} -snf libsmbclient.so.0 ${PREFIX}/lib/libsmbclient.so
	-@${MKDIR} ${EXAMPLESDIR}
	@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/libsmbclient/* ${EXAMPLESDIR}

.include "${MASTERDIR}/Makefile"
