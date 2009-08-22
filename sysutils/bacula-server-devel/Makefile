# New ports collection makefile for:	bacula
# Date created:				5 March 2006
# Whom:					Dan Langille <dan@langille.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
DISTVERSION=	2.5.42-b2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/bacula/OldFiles
PKGNAMESUFFIX?=	-server-devel
MAINTAINER=	dan@langille.org
COMMENT?=	The network backup solution (server) - DEVELOPMENT Version

CONFLICTS=	bacula-server-[0-9]* bacula-client-[0-9]*

UNIQUENAME?=${PORTNAME}${PKGNAMESUFFIX}
.if !defined(WITH_BAT)
.if !defined(WITH_CLIENT_ONLY)
USE_RC_SUBR?=	bacula-dir bacula-sd
.endif


.if defined(WITH_CLIENT_ONLY)
SUB_FILES+=	pkg-message.client
.else
SUB_FILES+=	pkg-message.server
.endif
.endif

# The user/group IDs below are registered, see
# http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/book.html#DADS-UID
#
BACULA_DIR?=/var/db/bacula
#
MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tcp-wrappers=/usr/lib \
		--enable-smartalloc \
		--with-working-dir=${BACULA_DIR} \
		--with-scriptdir=${PREFIX}/share/${PORTNAME} \
		--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR} \
		--with-readline=yes \
		--disable-conio \
		--enable-batch-insert \
		--with-plugindir=${LOCALBASE}/lib \
		--with-libdir=${PREFIX}lib/bacula \
		--with-dump-email=root@localhost \
		--with-job-email=root@localhost \
		--with-db-name=bacula \
		--with-db-user=bacula \
		--with-baseport=9101

.if defined(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=		--with-fd-user=root \
		--with-fd-group=wheel
.else
CONFIGURE_ARGS+=--with-dir-user=bacula \
		--with-dir-group=bacula \
		--with-sd-user=bacula \
		--with-sd-group=operator
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I/usr/include/readline -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.for opt in ${ALL_OPTIONS}
.if defined(WITH_${opt})
BATCH=	yes
.endif
.endfor

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

.if defined(WITH_CLIENT_ONLY)
OPTIONS=	WXCONSOLE "Build with wxGTK based GUI console: deprecated" off
OPTIONS+=	GNOMECONSOLE "Build with GNOME based GUI console: deprecated" off
.elif defined(WITH_BAT)
OPTIONS=	
.else
OPTIONS=	SQLITE3 "Use SqLite-3 database instead of SqLite-2" off
OPTIONS+=	MYSQL "Use MySQL database instead of SqLite" off
OPTIONS+=	POSTGRESQL "Use PostgreSQL database instead of SqLite" off
OPTIONS+=	MTX "Install mtx for control of autochanger devices" off
.endif

OPTIONS+=	NLS "Native Language Support via gettext utilities" on
OPTIONS+=	OPENSSL "Enable OpenSSL for encrypted communication" off

# Prepare if bgnome-console is selected this must be happen before
# include of bsd.port.pre.mk!
WANT_GNOME=	yes
.if defined(WITH_GNOMECONSOLE)
USE_GNOME=	libgnome gnomelibs libgnomeui
.endif

PLIST_SUB+=	BACULA_DIR=${BACULA_DIR}

.if !defined(WITH_BAT)
PLIST_SUB+=	BACULA_DIR=${BACULA_DIR}
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if definedf defined(WITH_CLIENT_ONLY) && (${OSVERSION} >= 800000)
BROKEN=	Does not build due to missing llistxattr
.endif

# Client only or full server version
.if defined(WITH_CLIENT_ONLY)
CONFFILES=	fd
CONFIGURE_ARGS+=	--enable-client-only

PKGDEINSTALL=	${PKGDIR}/pkg-deinstall.client
PKGINSTALL=	${PKGDIR}/pkg-install.client
# Build bgnome-console
.if defined(WITH_GNOMECONSOLE)
CONFIGURE_ARGS+=	--enable-gnome
PLIST_SUB+=		GNOMECONS=""
.else
# We didn't need GTK (it's not possible to put WANT_GNOME in an .if statement!)
WITHOUT_GNOME=		yes
PLIST_SUB+=		GNOMECONS="@comment "
.endif
# Build bwx-console
.if defined(WITH_WXCONSOLE)
USE_WX=			2.4
CONFIGURE_ARGS+=	--enable-wx-console
CONFIGURE_ENV+=		WXCONFIG="${WX_CONFIG}"
PLIST_SUB+=		WXCONS=""
.else
# We didn't need GTK (it's not possible to put WANT_GNOME in an .if statement!)
WITHOUT_GNOME=		yes
PLIST_SUB+=	 	WXCONS="@comment "
.endif
.else
# Server only Options
PLIST_SUB+=		GNOMECONS="@comment "
PLIST_SUB+=	 	WXCONS="@comment "
CONFFILES=		sd dir
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql=yes
USE_MYSQL=		yes
DBTYPE=			mysql
SUB_LIST+=		REQ_MYSQL=mysql REQ_PGSQL=""
.elif defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=yes
DBTYPE=			postgresql
SUB_LIST+=		REQ_MYSQL="" REQ_PGSQL=postgresql
.elif defined(WITH_SQLITE3)
CONFIGURE_ARGS+=	--with-sqlite3=yes
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
DBTYPE=			sqlite3
.else
CONFIGURE_ARGS+=	--with-sqlite=yes
LIB_DEPENDS+=		sqlite.2:${PORTSDIR}/databases/sqlite2
DBTYPE=			sqlite
.endif
PLIST_SUB+=		DBTYPE=${DBTYPE}
# Install mtx
.if defined(WITH_MTX)
RUN_DEPENDS+=		${LOCALBASE}/sbin/mtx:${PORTSDIR}/misc/mtx
.endif
.endif

.if defined(WITH_OPENSSL)
CONFIGURE_ARGS+=	--with-openssl
.endif

.if !defined(WITH_BAT)
.if defined(WITH_CLIENT_ONLY)
MAN8=bacula-fd.8 bconsole.8
.else
MAN8=bacula.8 bacula-dir.8 bacula-sd.8 bcopy.8 bextract.8 bls.8 bscan.8 btape.8 btraceback.8 dbcheck.8
MAN1=bsmtp.1 bacula-bgnome-console.1 bacula-tray-monitor.1 bacula-bwxconsole.1
.endif
.endif

MAKE_ARGS+=	-E MAN8 -E MAN1
MAKE_ENV+=	MAN8="${MAN8}" MAN1="${MAN1}"

pre-everything::
.if !defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "You may use the following build options (or make config):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CLIENT_ONLY=yes	if you only want the file daemon."
	@${ECHO_MSG} "  WITH_WXCONSOLE=yes	if you only want a wxGTK based GUI console."
	@${ECHO_MSG} "  WITH_GNOMECONSOLE=yes	if you only want a GNOME based GUI console."
	@${ECHO_MSG} "  WITH_MTX=yes		if you want to use mtx instead of chio for autochanger control."
	@${ECHO_MSG} "  WITH_SQLITE3=yes  	if you want SqLite-3 instead of SqLite-2 as the database."
.if !defined(WITH_MYSQL) && !defined(WITH_POSTGRESQL)
	@${ECHO_MSG} "  WITH_MYSQL=yes  	if you want MySQL instead of SqLite as the database."
	@${ECHO_MSG} "  WITH_POSTGRESQL=yes	if you want PostgreSQL instead of SqLite as the database."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The default DB is SQLite-2!"
.endif
	@${ECHO_MSG} "  WITH_OPENSSL=yes  	Enable OpenSSL for encrypted communication."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> Using ${DBTYPE} as the bacula database."
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} "===> Building file daemon only."
.endif

post-patch:
#	Default bconsole.conf is ${PREFIX}/etc
	@${REINPLACE_CMD} -e 's|./bconsole.conf|${PREFIX}/etc/bconsole.conf|g' ${WRKSRC}/src/console/console.c
.if defined(WITH_CLIENT_ONLY)
# 	In client port only install startup script out of script dir (see below post-install)
# 	Dont mkdir ${PREFIX}/share/bacula cause it's empty
	@${REINPLACE_CMD} -e 's|^\(fd_subdirs = .*\)scripts\(.*\)|\1\2|g' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|\(.*$${MKDIR} $${DESTDIR}$${scriptdir}\)|#\1|g' ${WRKSRC}/Makefile.in
.else
#	In server port don't install filed
	@${REINPLACE_CMD} -e '/^fd_subdirs = /s|src/filed||' -e 's|src/console||' ${WRKSRC}/Makefile.in
.endif

.if !target(pre-install)
pre-install:
	if [ ! -d "${BACULA_DIR}" ]; then \
		${ECHO_CMD} "creating ${BACULA_DIR}" ; \
		${MKDIR} ${BACULA_DIR}; \
	else \
		${ECHO_CMD} "${BACULA_DIR} already exists"; \
	fi

# 	Extend /etc/services and install UID/GID
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif


.if !target(post-install)
post-install:
.if defined(WITH_CLIENT_ONLY)
# 	Extend only /etc/services
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME}
# 	Console stuff
	if [ -f ${PREFIX}/etc/bconsole.conf.new ]; then \
		${ECHO_CMD} "etc/bconsole.conf.new" >> ${TMPPLIST}; \
		${CHGRP} bacula ${PREFIX}/etc/bconsole.conf.new; \
	elif [ -f ${PREFIX}/etc/bconsole.conf ]; then \
		${MV} ${PREFIX}/etc/bconsole.conf ${PREFIX}/etc/bconsole.conf.sample; \
		${CHGRP} bacula ${PREFIX}/etc/bconsole.conf.sample; \
		${ECHO_CMD} "etc/bconsole.conf.sample" >> ${TMPPLIST}; \
	fi
.if defined(WITH_WXCONSOLE)
	if [ -f ${PREFIX}/etc/bwx-console.conf.new ]; then \
		${ECHO_CMD} "etc/bwx-console.conf.new" >> ${TMPPLIST}; \
	elif [ -f ${PREFIX}/etc/bwx-console.conf ]; then \
		${MV} ${PREFIX}/etc/bwx-console.conf ${PREFIX}/etc/bwx-console.conf.sample; \
		${ECHO_CMD} "etc/bwx-console.conf.sample" >> ${TMPPLIST}; \
	fi
.endif
.if defined(WITH_GNOMECONSOLE)
	if [ -f ${PREFIX}/etc/bgnome-console.conf.new ]; then \
		${ECHO_CMD} "etc/bgnome-console.conf.new" >> ${TMPPLIST}; \
	elif [ -f ${PREFIX}/etc/bgnome-console.conf ]; then \
		${MV} ${PREFIX}/etc/bgnome-console.conf ${PREFIX}/etc/bgnome-console.conf.sample; \
		${ECHO_CMD} "etc/bgnome-console.conf.sample" >> ${TMPPLIST}; \
	fi
.endif

#	ensure that users in the bacula group can run bconsole
	${CHGRP} bacula ${PREFIX}/sbin/bconsole
.else
# 	Install config files and preserve existing ones
	${INSTALL_SCRIPT} ${FILESDIR}/chio-bacula ${PREFIX}/sbin
	if [ -f ${PREFIX}/etc/bacula-barcodes ]; then \
		${INSTALL_DATA} ${FILESDIR}/bacula-barcodes ${PREFIX}/etc/bacula-barcodes.new ; \
		${ECHO_CMD} "etc/bacula-barcodes.new" >> ${TMPPLIST}; \
	else \
		${INSTALL_DATA} ${FILESDIR}/bacula-barcodes ${PREFIX}/etc/bacula-barcodes.samples ; \
		${ECHO_CMD} "etc/bacula-barcodes.samples" >> ${TMPPLIST}; \
	fi
# 	chmod of bsmtp program so bacula can use it with dropped down permissions
	${CHMOD} o+x ${PREFIX}/sbin/bsmtp
	${CHOWN} -R bacula:bacula ${PREFIX}/share/bacula

.endif
# 	Install leaves existing conf files untouched. Respect this here!
	for na in ${CONFFILES}; do \
		if [ -f ${PREFIX}/etc/bacula-$$na.conf.new ]; then \
			${ECHO_CMD} "etc/bacula-$$na.conf.new" >> ${TMPPLIST}; \
		elif [ -f ${PREFIX}/etc/bacula-$$na.conf ]; then \
			${MV} ${PREFIX}/etc/bacula-$$na.conf ${PREFIX}/etc/bacula-$$na.conf.sample; \
			${ECHO_CMD} "etc/bacula-$$na.conf.sample" >> ${TMPPLIST}; \
		fi; \
	done

	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
