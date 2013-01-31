# $FreeBSD$

PORTREVISION=		0
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
SAMBA_INSTALL_LIBS=	libsmbclient

MAN7=			libsmbclient.7

ALL_TARGET=		${SAMBA_INSTALL_LIBS}

do-install:
			-@${MKDIR} ${MAN7PREFIX}/man/man7
.for man in ${MAN7}
			${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/${man} ${MAN7PREFIX}/man/man7
.endfor
			-@${MKDIR} ${PREFIX}/include
			${INSTALL_DATA} ${WRKSRC}/include/libsmbclient.h ${PREFIX}/include
			-@${MKDIR} ${PREFIX}/lib
.for lib in ${SAMBA_INSTALL_LIBS}
			${INSTALL_SCRIPT} ${WRKSRC}/bin/${lib}.a ${PREFIX}/lib
			${INSTALL_SCRIPT} ${WRKSRC}/bin/${lib}.so ${PREFIX}/lib/${lib}.so.0
			${LN} -snf ${lib}.so.0 ${PREFIX}/lib/${lib}.so
.endfor
			-@${MKDIR} ${EXAMPLESDIR}
			@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/libsmbclient/ ${EXAMPLESDIR}

.include "${MASTERDIR}/Makefile"
