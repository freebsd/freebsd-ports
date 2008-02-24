# Don't check for python presence
CONFIGURE_ARGS+=	--without-python
# We WANT shared libs
CONFIGURE_ARGS+=	--with-libsmbclient
SAMBA_INSTALL_LIBS=	libsmbclient

.if !defined(WITHOUT_ADDNS)
CONFIGURE_ARGS+=	--with-libaddns
SAMBA_INSTALL_LIBS+=	libaddns
PLIST_SUB+=		ADDNS=""
.else
CONFIGURE_ARGS+=	--without-libaddns
PLIST_SUB+=		ADDNS="@comment "
.endif

.if !defined(WITHOUT_SHAREMODES)
CONFIGURE_ARGS+=	--with-libsmbsharemodes
SAMBA_INSTALL_LIBS+=	libsmbsharemodes
PLIST_SUB+=		SHAREMODES=""
.else
CONFIGURE_ARGS+=	--without-libsmbsharemodes
PLIST_SUB+=		SHAREMODES="@comment "
.endif

MAN7=			libsmbclient.7

do-build:
	cd ${WRKSRC} && ${MAKE} proto bin/.dummy
	cd ${WRKSRC} && ${MAKE} libsmbclient
.if !defined(WITHOUT_ADDNS)
	cd ${WRKSRC} && ${MAKE} libaddns
.endif
.if !defined(WITHOUT_SHAREMODES)
	cd ${WRKSRC} && ${MAKE} libsmbsharemodes
.endif

do-install:
	-@${MKDIR} ${MAN8PREFIX}/man/man7
.for man in ${MAN7}
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/${man} ${MAN7PREFIX}/man/man7
.endfor
	-@${MKDIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/libsmbclient.h ${PREFIX}/include
.if !defined(WITHOUT_ADDNS)
	${INSTALL_DATA} ${WRKSRC}/libaddns/addns.h ${PREFIX}/include
.endif
	-@${MKDIR} ${PREFIX}/lib
.for lib in ${SAMBA_INSTALL_LIBS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${lib}.a ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${lib}.so ${PREFIX}/lib/${lib}.so.0
	${LN} -snf ${lib}.so.0 ${PREFIX}/lib/${lib}.so
.endfor
	-@${MKDIR} ${EXAMPLESDIR}
	@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/libsmbclient ${EXAMPLESDIR}
