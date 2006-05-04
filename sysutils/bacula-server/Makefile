# New ports collection makefile for:	bacula
# Date created:				24 February 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
DISTVERSION=	1.38.9
#PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bacula
PKGNAMESUFFIX?=	-server

MAINTAINER=	dan@langille.org
COMMENT?=	The network backup solution (server)

CONFLICTS=	bacula-server-devel-[0-9]* bacula-client-devel-[0-9]*

UNIQUENAME?=${PORTNAME}${PKGNAMESUFFIX}

USE_RC_SUBR?=	bacula-dir bacula-sd

SUB_FILES+=	pkg-message

# The user/group IDs below are registered, see
# http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/book.html#DADS-UID
#
BACULA_DIR?=/var/db/bacula
#
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcp-wrappers=/usr/lib \
		--enable-smartalloc \
		--with-working-dir=${BACULA_DIR} \
		--with-scriptdir=${PREFIX}/share/${PORTNAME} \
		--mandir=${PREFIX}/man \
		--with-readline=yes \
		--disable-conio

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

ALL_OPTIONS=	CLIENT_ONLY WXCONSOLE GNOMECONSOLE SQLITE3 MYSQL POSTGRESQL MTX OPENSSL DOCS

.for opt in ${ALL_OPTIONS}
.if defined(WITH_${opt})
BATCH=	yes
.endif
.endfor

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

.if defined(WITH_CLIENT_ONLY)
OPTIONS+=	WXCONSOLE "Build with wxGTK based GUI console" off
OPTIONS+=	GNOMECONSOLE "Build with GNOME based GUI console" off
OPTIONS+=	DOCS "Install documention" off
.else
OPTIONS=	SQLITE3 "Use SqLite-3 database instead of SqLite-2" off
OPTIONS+=	MYSQL "Use MySQL database instead of SqLite" off
OPTIONS+=	POSTGRESQL "Use PostgreSQL database instead of SqLite" off
OPTIONS+=	MTX "Install mtx for control of autochanger devices" off
.endif

OPTIONS+=	OPENSSL "Enable OpenSSL for encrypted communication" off

# Prepare if gnome-console is selected this must be happen before
# include of bsd.port.pre.mk!
WANT_GNOME=	yes
.if defined(WITH_GNOMECONSOLE)
USE_GNOME=	libgnome
.endif

PLIST_SUB+=	BACULA_DIR=${BACULA_DIR}

MAN8=		bacula.8

.include <bsd.port.pre.mk>

DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz
.if defined(WITH_DOCS)
DISTFILES+=	${PORTNAME}-docs-${PORTVERSION}.tar.gz
.endif

.if defined(WITH_DOCS)
PORTDOCS=	ReleaseNotes bacula.pdf developers.pdf kernstodo manual bacula-web
.endif

# Client only or full server version
.if defined(WITH_CLIENT_ONLY)
CONFFILES=	fd
CONFIGURE_ARGS+=	--enable-client-only

PKGDEINSTALL=	${PKGDIR}/pkg-deinstall.client
PKGINSTALL=	${PKGDIR}/pkg-install.client
# Build gnome-console
.if defined(WITH_GNOMECONSOLE)
CONFIGURE_ARGS+=	--enable-gnome
PLIST_SUB+=		GNOMECONS=""
.else
# We didn't need GTK (it's not possible to put WANT_GNOME in an .if statement!)
WITHOUT_GNOME=		yes
PLIST_SUB+=		GNOMECONS="@comment "
.endif
# Build wx-console
.if defined(WITH_WXCONSOLE)
CONFIGURE_ARGS+=	--enable-wx-console
LIB_DEPENDS+=		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24
CONFIGURE_ENV+=		WXCONFIG=${X11BASE}/bin/wxgtk2-2.4-config
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
DBTYPE=			sqlite
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

.if defined(WITH_CLIENT_ONLY)
MAN8=bacula.8
.endif

pre-everything::
.if !defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "=======> ATTENTION <======="
	@${ECHO_MSG} "===> Note that there is a pthreads problem, which leads to the loss of 500kB"
	@${ECHO_MSG} "===> of data at the end of an tape. This is corrected in newer versions of FreeBSD"
	@${ECHO_MSG} "===> READ ${WRKSRC}/platforms/freebsd/pthreads-fix.txt"
	@${ECHO_MSG} ""
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
	@${ECHO_MSG} "  WITH_DOCS=yes  		if you want the documentation installed."
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
	${REINPLACE_CMD} -e 's|\(.*$$(MKDIR) $$(DESTDIR)$$(scriptdir)\)|#\1|g' ${WRKSRC}/Makefile.in
.else
#	In server port don't install filed
	@${REINPLACE_CMD} -e 's|^all_subdirs = .*|all_subdirs = scripts src\/lib src\/findlib $${subdirs}|g' ${WRKSRC}/Makefile.in
.endif

pre-install:
	if [ ! -d "${BACULA_DIR}" ]; then \
		${ECHO_CMD} "creating ${BACULA_DIR}" ; \
		${MKDIR} ${BACULA_DIR}; \
	else \
		${ECHO_CMD} "${BACULA_DIR} already exists"; \
	fi

.if !defined(WITH_CLIENT_ONLY)
# 	Extend /etc/services and install UID/GID
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif

post-install:
.if defined(WITH_CLIENT_ONLY)
# 	Extend only /etc/services
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME}
# 	Console stuff
	if [ -f ${PREFIX}/etc/bconsole.conf.new ]; then \
		${ECHO_CMD} "etc/bconsole.conf.new" >> ${TMPPLIST}; \
	elif [ -f ${PREFIX}/etc/bconsole.conf ]; then \
		${MV} ${PREFIX}/etc/bconsole.conf ${PREFIX}/etc/bconsole.conf.sample; \
		${ECHO_CMD} "etc/bconsole.conf.sample" >> ${TMPPLIST}; \
	fi
.if defined(WITH_WXCONSOLE)
	if [ -f ${PREFIX}/etc/wx-console.conf.new ]; then \
		${ECHO_CMD} "etc/wx-console.conf.new" >> ${TMPPLIST}; \
	elif [ -f ${PREFIX}/etc/wx-console.conf ]; then \
		${MV} ${PREFIX}/etc/wx-console.conf ${PREFIX}/etc/wx-console.conf.sample; \
		${ECHO_CMD} "etc/wx-console.conf.sample" >> ${TMPPLIST}; \
	fi
.endif
.if defined(WITH_GNOMECONSOLE)
	if [ -f ${PREFIX}/etc/gnome-console.conf.new ]; then \
		${ECHO_CMD} "etc/gnome-console.conf.new" >> ${TMPPLIST}; \
	elif [ -f ${PREFIX}/etc/gnome-console.conf ]; then \
		${MV} ${PREFIX}/etc/gnome-console.conf ${PREFIX}/etc/gnome-console.conf.sample; \
		${ECHO_CMD} "etc/gnome-console.conf.sample" >> ${TMPPLIST}; \
	fi
.endif

.if defined(WITH_CLIENT_ONLY)
	${INSTALL_MAN} ${WRKSRC}/scripts/bacula.man ${PREFIX}/man/man8/bacula.8
.endif

# Documentation is only installed in -client port
.if defined(WITH_DOCS)
	for na in manual bacula-web; do \
		${MKDIR} ${DOCSDIR}/$$na ;\
		cd ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION} && ${FIND} $$na | \
			${CPIO} -pdm -L -R root:wheel ${DOCSDIR}; \
	done
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/ReleaseNotes ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION}/manual/bacula.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION}/developers/developers.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/kernstodo ${DOCSDIR}
.endif

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

# Inform user after install about important things ....
	@${ECHO_MSG} "*********************************************************************"
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} "Sample files are installed in ${PREFIX}/etc:"
	@${ECHO_MSG} "  bconsole.conf.sample, bacula-barcodes.sample, bacula-fd.conf.sample"
.if !defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "  bacula-sd.conf.sample, bacula-dir.conf.sample"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "An auto-changer manipulation script based on FreeBSDs"
	@${ECHO_MSG} "chio command is included and installed at"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  ${PREFIX}/sbin/chio-bacula"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please have a look at it if you want to use an"
	@${ECHO_MSG} "autochanger. You have to configure the usage in"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  ${PREFIX}/etc/bacula-dir.conf"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take care of correct permissions for changer and"
	@${ECHO_MSG} "tape device (e.g. /dev/ch0 and /dev/n[r]sa0) i.e."
	@${ECHO_MSG} "they must be accessible by user bacula."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Due to lack of some features in the FreeBSD tape driver"
	@${ECHO_MSG} "implementation you MUST add some OS dependent options to"
	@${ECHO_MSG} "the bacula-sd.conf file:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  Hardware End of Medium = no;"
	@${ECHO_MSG} "  Backward Space Record = no;"
	@${ECHO_MSG} "  Backward Space File = no;"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "With 2 filemarks at EOT (see man mt):"
	@${ECHO_MSG} "  Fast Forward Space File = no;"
	@${ECHO_MSG} "  BSF at EOM = yes;"
	@${ECHO_MSG} "  TWO EOF = yes;"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "With 1 filemarks at EOT (see man mt):"
	@${ECHO_MSG} "  Fast Forward Space File = yes;"
	@${ECHO_MSG} "  BSF at EOM = no;"
	@${ECHO_MSG} "  TWO EOF = no;"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE: YOU CAN SWITCH EOT model ONLY when starting"
	@${ECHO_MSG} "      from scratch with EMPTY tapes!!!!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "It is also important that all the scripts accessed"
	@${ECHO_MSG} "by RunBeforeJob and RunAfterJob can be executed by"
	@${ECHO_MSG} "the user bacula."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For USB support read the bacula manual!! It could be necessary"
	@${ECHO_MSG} "to configure/compile a new kernel!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Look at ${PREFIX}/share/bacula/update_bacula_tables for"
	@${ECHO_MSG} "database update procedure. Details can be found in the"
	@${ECHO_MSG} "ReleaseNotes"
.endif
	@${ECHO_MSG} "*********************************************************************"

.if !defined(WITH_CLIENT_ONLY)
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
