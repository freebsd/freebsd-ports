# New ports collection makefile for:	samba-libsmbclient
# Date created:				23 Juli 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTREVISION=		0
PORTEPOCH=		0
PKGNAMESUFFIX=		-libsmbclient

COMMENT=		Shared libs from the samba package

CONFLICTS=

SAMBA_PORT=		samba3
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
PKGDIR=			${.CURDIR}

INSTALLS_SHLIB=		yes

# We WANT shared libs
CONFIGURE_ARGS+=	--with-libsmbclient
SAMBA_INSTALL_LIBS=	libsmbclient

.if defined(WITH_SHAREMODES)
CONFIGURE_ARGS+=	--with-libsmbsharemodes
SAMBA_INSTALL_LIBS+=	libsmbsharemodes
PLIST_SUB+=		SHAREMODES=""
.else
PLIST_SUB+=		SHAREMODES="@comment "
.endif

.if defined(WITH_MSRPC)
CONFIGURE_ARGS+=	--with-libmsrpc
SAMBA_INSTALL_LIBS+=	libmsrpc
PLIST_SUB+=		MSRPC=""
.else
PLIST_SUB+=		MSRPC="@comment "
.endif
# Don't check for python presence
CONFIGURE_ARGS+=	--without-python

MAN7=			libsmbclient.7

do-build:
	cd ${WRKSRC} && ${MAKE} proto
	cd ${WRKSRC} && ${MAKE} libsmbclient
.if defined(WITH_SHAREMODES)
	cd ${WRKSRC} && ${MAKE} libsmbsharemodes
.endif
.if defined(WITH_MSRPC)
	cd ${WRKSRC} && ${MAKE} cac
.endif

do-install:
	-@${MKDIR} ${MAN8PREFIX}/man/man7
.for man in ${MAN7}
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/${man} ${MAN7PREFIX}/man/man7
.endfor
	-@${MKDIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/libsmbclient.h ${PREFIX}/include
.if defined(WITH_MSRPC)
	${INSTALL_DATA} ${WRKSRC}/include/libmsrpc.h ${PREFIX}/include
.endif
	-@${MKDIR} ${PREFIX}/lib
.for lib in ${SAMBA_INSTALL_LIBS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${lib}.a ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${lib}.so ${PREFIX}/lib/${lib}.so.0
	${LN} -snf ${lib}.so.0 ${PREFIX}/lib/${lib}.so
.endfor
	-@${MKDIR} ${EXAMPLESDIR}
	@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/libsmbclient ${EXAMPLESDIR}
.if defined(WITH_MSRPC)
	@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/libmsrpc ${EXAMPLESDIR}
.endif

.include "${MASTERDIR}/Makefile"
