# $FreeBSD$

PORTREVISION=		2
PORTEPOCH=		0
PKGNAMESUFFIX=		-libsmbclient

COMMENT=		Shared lib from the samba package

CONFLICTS=

SAMBA_PORT=		samba36
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
PKGDIR=			${.CURDIR}

USE_LDCONFIG=		${PREFIX}/lib

# We WANT shared libs
CONFIGURE_ARGS+=	--with-libsmbclient

ALL_TARGET=		libsmbclient

do-install:
			-@${MKDIR} ${STAGEDIR}${MAN7PREFIX}/man/man7
			${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/libsmbclient.7 ${STAGEDIR}${MAN7PREFIX}/man/man7
			-@${MKDIR} ${STAGEDIR}${PREFIX}/include
			${INSTALL_DATA} ${WRKSRC}/include/libsmbclient.h ${STAGEDIR}${PREFIX}/include
			${INSTALL_DATA} ${WRKSRC}/pkgconfig/smbclient.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
			-@${MKDIR} ${STAGEDIR}${PREFIX}/lib
			${INSTALL_SCRIPT} ${WRKSRC}/bin/libsmbclient.a ${STAGEDIR}${PREFIX}/lib
			${INSTALL_SCRIPT} ${WRKSRC}/bin/libsmbclient.so ${STAGEDIR}${PREFIX}/lib/libsmbclient.so.0
			${LN} -snf libsmbclient.so.0 ${STAGEDIR}${PREFIX}/lib/libsmbclient.so
			-@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
			@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/libsmbclient/ ${STAGEDIR}${EXAMPLESDIR}

.include "${MASTERDIR}/Makefile"
