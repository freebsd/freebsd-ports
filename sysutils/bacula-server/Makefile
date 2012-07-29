# New ports collection makefile for:	bacula
# Date created:				24 February 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
DISTVERSION=	5.2.10
CATEGORIES?=	sysutils
MASTER_SITES=	SF/bacula/bacula/${PORTVERSION}

MAINTAINER=	dan@langille.org
COMMENT?=	The network backup solution (server)

CONFLICTS=	bacula-server-devel-[0-9]* bacula-client-devel-[0-9]* bacula-docs-devel-[0-9]*

UNIQUENAME?=	${PORTNAME}${PKGNAMESUFFIX}

USERS=		bacula
GROUPS=		${USERS}

PLIST_SUB+=	MAJOR=${PORTVERSION:R:R}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I/usr/include/readline -I${LOCALBASE}/include

.if !defined(WITH_BAT) && !defined(WITH_NAGIOS_CHECK_ONLY)  #Till end of the file
PKGNAMESUFFIX?=	-server

PORTDOCS=	VERIFYING \
		technotes \
		ChangeLog \
		README \
		ReleaseNotes \
		LICENSE \
		INSTALL

.if !defined(WITH_CLIENT_ONLY)
USE_RC_SUBR?=	bacula-dir bacula-sd
.endif

.if defined(WITH_CLIENT_ONLY)
SUB_FILES+=	pkg-install.client pkg-deinstall.client pkg-message.client
.else
SUB_FILES+=	pkg-install.server pkg-deinstall.server pkg-message.server
.endif

#
MANCOMPRESSED=	yes
CONFIGURE_ARGS+=--with-tcp-wrappers=/usr/lib \
		--enable-smartalloc \
		--with-working-dir=${BACULA_DIR} \
		--with-scriptdir=${PREFIX}/share/${PORTNAME} \
		--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR} \
		--with-readline=yes \
		--disable-conio \
		--enable-batch-insert \
		--with-plugindir=${LOCALBASE}/lib \
		--with-dump-email=root@localhost \
		--with-job-email=root@localhost \
		--with-db-name=bacula \
		--with-sbin-perm=755 \
		--with-db-user=bacula \
		--with-baseport=9101

.if defined(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=--with-fd-user=root \
		--with-fd-group=wheel
.else
CONFIGURE_ARGS+=--with-dir-user=${BACULA_USER} \
		--with-dir-group=${BACULA_GROUP} \
		--with-sd-user=${BACULA_USER} \
		--with-sd-group=operator
.endif

.if defined(WITH_CLIENT_ONLY)
OPTIONS=	WXCONSOLE "Build with wxGTK based GUI console: deprecated" off
OPTIONS+=	SFDAEMON "Build with staticly compiled file daemon" off
.else
OPTIONS=	SQLITE3 "Use SQLite-3 database" off
OPTIONS+=	MYSQL "Use MySQL database" off
OPTIONS+=	POSTGRESQL "Use PostgreSQL database" off
OPTIONS+=	MTX "Install mtx for control of autochanger devices" off
.endif
OPTIONS+=	NLS "Native Language Support via gettext utilities" on
OPTIONS+=	OPENSSL "Enable OpenSSL for encrypted communication" on

# The user/group IDs below are registered, see
# http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/book.html#DADS-UID
#
BACULA_USER?=	bacula
BACULA_GROUP?=	${BACULA_USER}
BACULA_UID?=	910
BACULA_GID?=	${BACULA_UID}
BACULA_DIR?=	/var/db/bacula

PLIST_SUB+=	BACULA_DIR=${BACULA_DIR}

SUB_LIST=	BACULA_USER=${BACULA_USER} \
		BACULA_GROUP=${BACULA_GROUP} \
		BACULA_UID=${BACULA_UID} \
		BACULA_GID=${BACULA_GID} \
		BACULA_DIR=${BACULA_DIR}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

# overridden if client install
PKGDEINSTALL=	${FILESDIR}/pkg-deinstall.server
PKGINSTALL=	${FILESDIR}/pkg-install.server

# Client only or full server version
.if defined(WITH_CLIENT_ONLY)
CONFFILES=	fd
# --disable-xattr is temporary to allow build with 8-current
CONFIGURE_ARGS+=	--enable-client-only --disable-xattr
PKGDEINSTALL=	${FILESDIR}/pkg-deinstall.client
PKGINSTALL=	${FILESDIR}/pkg-install.client
# Build a static fd binary.
.if defined(WITH_SFDAEMON)
CONFIGURE_ARGS+=	--enable-static-fd
CONFIGURE_ARGS+=	--disable-libtool
PLIST_SUB+=	SFDAEMON=""
PLIST_SUB+=	NOSF="@comment "
.else
PLIST_SUB+=	SFDAEMON="@comment "
PLIST_SUB+=	NOSF=""
.endif
#Build bwx-console is deprecated use bacula-bat instead
.if defined(WITH_WXCONSOLE)
IGNORE=			please use sysutils/bacula-bat instead of wxconsole
USE_WX=			2.4
CONFIGURE_ARGS+=	--enable-bwx-console
CONFIGURE_ENV+=		WXCONFIG="${WX_CONFIG}"
PLIST_SUB+=		WXCONS=""
.else
PLIST_SUB+=		WXCONS="@comment "
.endif
.else
# Server only Options
PLIST_SUB+=		WXCONS="@comment "
CONFFILES=		sd dir
# Server default database
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql=yes
USE_MYSQL=		yes
DBTYPE=			mysql
SUB_LIST+=		REQ_MYSQL=mysql REQ_PGSQL=""
.elif defined(WITH_SQLITE3)
CONFIGURE_ARGS+=	--with-sqlite3=yes
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
DBTYPE=			sqlite3
.else
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=yes
DBTYPE=			postgresql
SUB_LIST+=		REQ_MYSQL="" REQ_PGSQL=postgresql
.endif
PLIST_SUB+=		DBTYPE=${DBTYPE}
# Install mtx
.if defined(WITH_MTX)
RUN_DEPENDS+=		${LOCALBASE}/sbin/mtx:${PORTSDIR}/misc/mtx
.endif
.endif

.if !defined(WITHOUT_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--with-openssl="no"
.endif

.if defined(WITH_CLIENT_ONLY)
MAN8=			bacula-fd.8 bconsole.8
EXTRA_PATCHES+=		${FILESDIR}/extra__manpages__Makefile.in
.else
MAN1=			bat.1 bsmtp.1 bacula-tray-monitor.1 bacula-bwxconsole.1
MAN8=			bacula.8 bacula-dir.8 bacula-fd.8 bacula-sd.8 bconsole.8 \
			bcopy.8 bextract.8 bls.8 bregex.8 bscan.8 btape.8 \
			btraceback.8 bwild.8 dbcheck.8
.endif

pre-everything::
.if !defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "You may use the following build options (or make config):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CLIENT_ONLY=yes	if you only want the file daemon."
#	@${ECHO_MSG} "  WITH_WXCONSOLE=yes	if you only want a wxGTK based GUI console."
	@${ECHO_MSG} "  WITH_MTX=yes		if you want to use mtx instead of chio for autochanger control."
	@${ECHO_MSG} "  WITH_SQLITE3=yes  	if you want SQLite-3 as the database (not recommended)."
.if !defined(WITH_MYSQL) && !defined(WITH_POSTGRESQL)
	@${ECHO_MSG} "  WITH_MYSQL=yes  	if you want MySQL as the database."
	@${ECHO_MSG} "  WITH_POSTGRESQL=yes	if you want PostgreSQL as the database."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The default DB is PostgreSQL!"
.endif
	@${ECHO_MSG} "  WITH_OPENSSL=yes  	Enable OpenSSL for encrypted communication."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> Using ${DBTYPE} as the bacula database."
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} "You may use the following build options (or make config):"
	@${ECHO_MSG} "  WITH_SFDAEMON=yes	if you want staticly compiled file daemon (client)."
	@${ECHO_MSG} "===> Building file daemon only."
.endif

post-patch:
#	Respect NOPORTDOCS
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/docdir/d' ${WRKSRC}/Makefile.in
.endif
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

#	on a fresh install, the .new suffix is not used
	if [ -f ${PREFIX}/etc/bacula-dir.conf.new ]; then \
		${CHGRP} bacula ${PREFIX}/etc/bacula-dir.conf.new; \
	else \
		${CHGRP} bacula ${PREFIX}/etc/bacula-dir.conf; \
	fi

	${CHGRP} bacula ${PREFIX}/sbin/dbcheck

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

	${CHGRP} wheel ${PREFIX}/etc

	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
.endif # if !defined(WITH_BAT) && !defined(WITH_NAGIOS_CHECK_ONLY)
