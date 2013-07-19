# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bacula
DISTVERSION=	5.2.12
PORTREVISION?=	1
CATEGORIES?=	sysutils
MASTER_SITES=	SF/bacula/bacula/${PORTVERSION}
PKGNAMEPREFIX?=	#
PKGNAMESUFFIX?=	-server

MAINTAINER=	dan@langille.org
COMMENT?=	Network backup solution (server)

UNIQUENAME?=	${PORTNAME}${PKGNAMESUFFIX}

USERS=		bacula
GROUPS=		${USERS}

PLIST_SUB+=	MAJOR=${PORTVERSION:R:R}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I/usr/include/readline -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE?=	SQLITE3 MYSQL PGSQL MTX PYTHON NLS OPENSSL
OPTIONS_DEFAULT?=	NLS OPENSSL PGSQL
MTX_DESC=		Install mtx for control of autochanger devices

.include <bsd.port.options.mk>

.if ${PKGNAMESUFFIX} == "-client" || ${PKGNAMESUFFIX} == "-server"  #Till end of the file

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--with-python=yes
.endif

.if !defined(WITH_CLIENT_ONLY)
LIB_DEPENDS+=	bac:${PORTSDIR}/sysutils/bacula-client
USE_RC_SUBR?=	bacula-dir bacula-sd
.endif

.if defined(WITH_CLIENT_ONLY)
SUB_FILES+=	pkg-install.client pkg-deinstall.client pkg-message.client
.else
SUB_FILES+=	pkg-install.server pkg-deinstall.server pkg-message.server
.endif

MANCOMPRESSED=	yes
CONFIGURE_ARGS+=--with-tcp-wrappers=/usr/lib \
		--enable-smartalloc \
		--sysconfdir=${ETCDIR} \
		--with-working-dir=${BACULA_DIR} \
		--with-scriptdir=${PREFIX}/share/${PORTNAME} \
		--with-readline=yes \
		--disable-conio \
		--enable-batch-insert \
		--with-plugindir=${PREFIX}/lib \
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

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
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
CONFIGURE_ARGS+=	--enable-client-only

PKGDEINSTALL=	${FILESDIR}/pkg-deinstall.client
PKGINSTALL=	${FILESDIR}/pkg-install.client
.else
# Server only Options
CONFFILES=		sd dir
# Server default database
.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql=yes
USE_MYSQL=		yes
DBTYPE=			mysql
SUB_LIST+=		REQ_MYSQL=mysql REQ_PGSQL=""
.elif ${PORT_OPTIONS:MSQLITE3}
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
.if ${PORT_OPTIONS:MMTX}
RUN_DEPENDS+=		${LOCALBASE}/sbin/mtx:${PORTSDIR}/misc/mtx
.endif
.endif

.if ${PORT_OPTIONS:MOPENSSL}
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--with-openssl="no"
.endif

.if defined(WITH_CLIENT_ONLY)
MAN8+=	bacula-fd.8 bconsole.8
.else
MAN8+=	bacula.8 bacula-dir.8 bacula-sd.8 bcopy.8 bextract.8 bls.8 bscan.8 \
	btape.8 btraceback.8 dbcheck.8 bwild.8 bregex.8
MAN1+=	bsmtp.1 bacula-tray-monitor.1 bacula-bwxconsole.1
.endif

MAKE_ENV+=	MAN8="${MAN8}" MAN1="${MAN1}"

pre-everything::
.if !defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "You may use the following build options (or make config):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CLIENT_ONLY=yes	if you only want the file daemon."
	@${ECHO_MSG} "  WITH_MTX=yes		if you want to use mtx instead of chio for autochanger control."
	@${ECHO_MSG} "  WITH_PYTHON=yes		Enable Python scripting in the director."
	@${ECHO_MSG} "  WITH_SQLITE3=yes  	if you want SQLite-3 as the database (not recommended)."
.if ! ${PORT_OPTIONS:MMYSQL} && ! ${PORT_OPTIONS:MPGSQL}
	@${ECHO_MSG} "  WITH_MYSQL=yes  	if you want MySQL as the database."
	@${ECHO_MSG} "  WITH_PGSQL=yes		if you want PostgreSQL as the database."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The default DB is PostgreSQL!"
.endif
	@${ECHO_MSG} "  WITH_OPENSSL=yes  	Enable OpenSSL for encrypted communication."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> Using ${DBTYPE} as the bacula database."
	@${ECHO_MSG} ""
.endif

post-patch:
#	This port does not install docs.  See bacula-docs for that
	${REINPLACE_CMD} -e '/docdir/d' ${WRKSRC}/Makefile.in
#	Change $(ECHO) to echo in some Makefile.in files
	@${REINPLACE_CMD} -e 's|$$(ECHO)|echo|g' ${WRKSRC}/src/filed/Makefile.in \
		${WRKSRC}/src/console/Makefile.in
#	Default bconsole.conf is in ${ETCDIR}
	@${REINPLACE_CMD} -e 's|./bconsole.conf|${ETCDIR}/bconsole.conf|g' ${WRKSRC}/src/console/console.c
	@${REINPLACE_CMD} -e 's|^MAN8 =|MAN8 ?=|g' -e 's|^MAN1 =|MAN1 ?=|g' ${WRKSRC}/manpages/Makefile.in
.if defined(WITH_CLIENT_ONLY)
# 	In client port only install startup script out of script dir (see below post-install)
# 	Dont mkdir ${PREFIX}/share/bacula cause it's empty
	@${REINPLACE_CMD} -e 's|^\(fd_subdirs = .*\)scripts\(.*\)|\1\2|g' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|\(.*$${MKDIR} $${DESTDIR}$${scriptdir}\)|#\1|g' ${WRKSRC}/Makefile.in
.else
#	In server port don't install filed
	@${REINPLACE_CMD} -e '/^fd_subdirs = /s|src/filed||' -e 's|src/console||' \
		-e 's|src/lib||' -e 's|src/findlib||' -e 's|@FD_PLUGIN_DIR@||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|../lib/|$$(LOCALBASE)/lib/|g' -e 's|../findlib/|$$(LOCALBASE)/lib/|g' ${WRKSRC}/src/dird/Makefile.in \
		${WRKSRC}/src/stored/Makefile.in ${WRKSRC}/src/tools/Makefile.in
	@${REINPLACE_CMD} -e 's|fd_plugins.h|filed/fd_plugins.h|g' -e 's|dir_plugins.h|dird/dir_plugins.h|g' -e 's|stored.h|stored/stored.h|g' \
		${WRKSRC}/src/tools/bpluginfo.c
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
	if [ -f ${ETCDIR}/bconsole.conf.new ]; then \
		${ECHO_CMD} "etc/bconsole.conf.new" >> ${TMPPLIST}; \
		${CHGRP} bacula ${ETCDIR}/bconsole.conf.new; \
	elif [ -f ${ETCDIR}/bconsole.conf ]; then \
		${MV} ${ETCDIR}/bconsole.conf ${ETCDIR}/bconsole.conf.sample; \
		${CHGRP} bacula ${ETCDIR}/bconsole.conf.sample; \
		${ECHO_CMD} "etc/bacula/bconsole.conf.sample" >> ${TMPPLIST}; \
	fi

#	ensure that users in the bacula group can run bconsole
	${CHGRP} bacula ${PREFIX}/sbin/bconsole
.else
# 	Install config files and preserve existing ones
	${INSTALL_SCRIPT} ${FILESDIR}/chio-bacula ${PREFIX}/sbin
	if [ -f ${ETCDIR}/bacula-barcodes ]; then \
		${INSTALL_DATA} ${FILESDIR}/bacula-barcodes ${ETCDIR}/bacula-barcodes.new ; \
		${ECHO_CMD} "etc/bacula/bacula-barcodes.new" >> ${TMPPLIST}; \
	else \
		${INSTALL_DATA} ${FILESDIR}/bacula-barcodes ${ETCDIR}/bacula-barcodes.samples ; \
		${ECHO_CMD} "etc/bacula/bacula-barcodes.samples" >> ${TMPPLIST}; \
	fi
#	Add configuration files directory to packing list
	${ECHO_CMD} "@unexec rmdir %D/etc/bacula 2>/dev/null || true" >> ${TMPPLIST}
# 	chmod of bsmtp program so bacula can use it with dropped down permissions
	${CHMOD} o+x ${PREFIX}/sbin/bsmtp
	${CHOWN} -R bacula:bacula ${PREFIX}/share/bacula

#	on a fresh install, the .new suffix is not used
	if [ -f ${ETCDIR}/bacula-dir.conf.new ]; then \
		${CHGRP} bacula ${ETCDIR}/bacula-dir.conf.new; \
	else \
		${CHGRP} bacula ${ETCDIR}/bacula-dir.conf; \
	fi

	${CHGRP} bacula ${PREFIX}/sbin/dbcheck

.endif
# 	Install leaves existing conf files untouched. Respect this here!
	for na in ${CONFFILES}; do \
		if [ -f ${ETCDIR}/bacula-$$na.conf.new ]; then \
			${ECHO_CMD} "etc/bacula/bacula-$$na.conf.new" >> ${TMPPLIST}; \
		elif [ -f ${ETCDIR}/bacula-$$na.conf ]; then \
			${MV} ${ETCDIR}/bacula-$$na.conf ${ETCDIR}/bacula-$$na.conf.sample; \
			${ECHO_CMD} "etc/bacula/bacula-$$na.conf.sample" >> ${TMPPLIST}; \
		fi; \
	done

#	Add configuration files directory to packing list
	${ECHO_CMD} "@unexec rmdir %D/etc/bacula 2>/dev/null || true" >> ${TMPPLIST}

	${CHGRP} wheel ${PREFIX}/etc

	@${CAT} ${PKGMESSAGE}
.endif
.else
.include "${MASTERDIR}/Makefile.common"
.endif # -client and -server are defined
.include <bsd.port.mk>
