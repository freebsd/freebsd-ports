# New ports collection makefile for:	bacula
# Date created:				24 February 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
PORTVERSION=	1.34.6
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bacula

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE
COMMENT=	The network backup solution

# The user/group IDs below are registered, see
# http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/book.html#DADS-UID
#
BACULA_DIR=/var/db/bacula
#
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcp-wrappers=/usr/lib \
		--enable-smartalloc \
		--with-working-dir=${BACULA_DIR} \
		--with-scriptdir=${PREFIX}/share/bacula \
		--with-fd-user=root \
		--with-fd-group=wheel \
		--with-dir-user=bacula \
		--with-dir-group=bacula \
		--with-sd-user=bacula \
		--with-sd-group=operator \
		--with-readline=yes \
		--disable-conio

CONFIGURE_ENV+=	CPPFLAGS="-I/usr/include/readline -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	CLIENT_ONLY "Build bacula file daemon only" off
OPTIONS+=	WXCONSOLE "Build with wxGTK based GUI console" off
OPTIONS+=	GNOMECONSOLE "Build with GNOME based GUI console" off
OPTIONS+=	MYSQL "Use MySQL database instead of SqLite" off
OPTIONS+=	POSTGRESQL7 "Use PostgreSQL 7.X database instead of SqLite" off
OPTIONS+=	MTX "Install mtx for control of autochanger devices" off

# Prepare if gnome-console is selected this must be happen before
# include of bsd.port.pre.mk!
WANT_GNOME=	yes
.if defined(WITH_GNOMECONSOLE)
USE_GNOME=	libgnome
.endif

.include <bsd.port.pre.mk>

PLIST_SUB+=	BACULA_DIR=${BACULA_DIR}

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
LIB_DEPENDS+=		wx_gtk-2.4:${PORTSDIR}/x11-toolkits/wxgtk
CONFIGURE_ENV+=		WXCONFIG=${X11BASE}/bin/wxgtk-2.4-config
PLIST_SUB+=		WXCONS=""
.else
# We didn't need GTK (it's not possible to put WANT_GNOME in an .if statement!)
WITHOUT_GNOME=		yes
PLIST_SUB+=	 	WXCONS="@comment "
.endif

# Client only or full server version
.if defined(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=	--enable-client-only
PLIST_SUB+=		SERVER="@comment "
.else
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql=yes
USE_MYSQL=		yes
DBTYPE=			mysql
.elif defined(WITH_POSTGRESQL7)
CONFIGURE_ARGS+=	--with-postgresql=yes
LIB_DEPENDS+=		pq:${PORTSDIR}/databases/postgresql7
DBTYPE=			postgresql
.else
CONFIGURE_ARGS+=	--with-sqlite=yes
LIB_DEPENDS+=		sqlite:${PORTSDIR}/databases/sqlite
DBTYPE=			sqlite
.endif
PLIST_SUB+=		DBTYPE=${DBTYPE}
PLIST_SUB+=		SERVER=""
.endif

# Install mtx
.if defined(WITH_MTX)
RUN_DEPENDS+=		${LOCALBASE}/sbin/mtx:${PORTSDIR}/misc/mtx
.endif

PORTDOCS=	bacula.pdf ReleaseNotes html-manual/*

pre-everything::
.if !defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "=======> ATTENTION <======="
	@${ECHO_MSG} "######################################################"
	@${ECHO_MSG} "===> Please read the file"
	@${ECHO_MSG} "===>     ${DOCSDIR}/ReleaseNotes"
	@${ECHO_MSG} "===> for the upgrade procedure!"
	@${ECHO_MSG} "===> IF YOU IGNORE THIS you may !! LOSE DATA !!"
	@${ECHO_MSG} "######################################################"
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
.if !defined(WITH_MYSQL) && !defined(WITH_POSTGRESQL7)
	@${ECHO_MSG} "  WITH_MYSQL=yes  	if you want MySQL instead of SqLite as the database."
	@${ECHO_MSG} "  WITH_POSTGRESQL7=yes	if you want PostgreSQL 7.X instead of SqLite as the database."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The default DB is SQLite!"
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> Using ${DBTYPE} as the bacula database."
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} "===> Building file daemon only."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_CFLAGS}|g' ${WRKSRC}/configure

post-install:
.if defined(WITH_CLIENT_ONLY)
	# Extend only /etc/services
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME}
.else
	# Extend /etc/services and install UID/GID
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	# Install config files and preserve existing ones
	${INSTALL_SCRIPT} ${FILESDIR}/chio-bacula ${PREFIX}/sbin
	if [ -f ${PREFIX}/etc/bacula-barcodes ]; then \
		${INSTALL_DATA} ${FILESDIR}/bacula-barcodes ${PREFIX}/etc/bacula-barcodes.new ; \
		${ECHO_CMD} "etc/bacula-barcodes.new" >> ${TMPPLIST}; \
	else \
		${INSTALL_DATA} ${FILESDIR}/bacula-barcodes ${PREFIX}/etc/bacula-barcodes.samples ; \
		${ECHO_CMD} "etc/bacula-barcodes.samples" >> ${TMPPLIST}; \
	fi
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
.endif	# chmod of bsmtp program so bacula can use it with dropped down permissions
	${CHMOD} o+x ${PREFIX}/sbin/bsmtp
	${CHOWN} -R bacula:bacula ${PREFIX}/share/bacula
.endif
	# Install leaves existing conf files untouched. Respect this here!
	for na in sd fd dir; do \
		if [ -f ${PREFIX}/etc/bacula-$$na.conf.new ]; then \
			${ECHO_CMD} "etc/bacula-$$na.conf.new" >> ${TMPPLIST}; \
		elif [ -f ${PREFIX}/etc/bacula-$$na.conf ]; then \
			${MV} ${PREFIX}/etc/bacula-$$na.conf ${PREFIX}/etc/bacula-$$na.conf.sample; \
			${ECHO_CMD} "etc/bacula-$$na.conf.sample" >> ${TMPPLIST}; \
		fi \
	done; \

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html-manual
	cd ${WRKSRC}/doc && ${FIND} html-manual | \
		${CPIO} -pdm -L -R root:wheel ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bacula.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${DOCSDIR}
.endif

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
	@${ECHO_MSG} "With 2 filemart at EOT (see man mt):"
	@${ECHO_MSG} "  Fast Forward Space File = no;"
	@${ECHO_MSG} "  BSF at EOM = yes;"
	@${ECHO_MSG} "  TWO EOF = yes;"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "With 1 filemart at EOT (see man mt):"
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
.endif
	@${ECHO_MSG} "*********************************************************************"

.include <bsd.port.post.mk>
