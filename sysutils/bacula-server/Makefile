# New ports collection makefile for:	bacula
# Date created:				24 February 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
PORTVERSION=	1.32f4
#PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bacula
DISTNAME=	${PORTNAME}-1.32f-4

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
		--with-fd-user=root \
		--with-fd-group=wheel \
		--with-dir-user=bacula \
		--with-dir-group=bacula \
		--with-sd-user=bacula \
		--with-sd-group=operator

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	CLIENT_ONLY "Build bacule file daemon only" off
OPTIONS+=	MYSQL "Build for MySQL database instead of SqLite" off

.include <bsd.port.pre.mk>

# Default is full build with sqlite
.if defined(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=	--enable-client-only
PLIST_SUB+=		SERVER="@comment "
.else
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
DBTYPE=		mysql
.else
CONFIGURE_ARGS+=	--with-sqlite=yes
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite
DBTYPE=		sqlite
.endif
PLIST_SUB+=	DBTYPE=${DBTYPE}
PLIST_SUB+=	SERVER=""
.endif

PORTDOCS=	bacula.pdf html-manual/*

pre-everything::
.if !defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "=======> ATTENTION <======="
	@${ECHO_MSG} "===> Note that there is a pthreads problem, which leads to the loss of 500kB"
	@${ECHO_MSG} "===> of data at the end of an tape. This is corrected in FreeBSD"
	@${ECHO_MSG} "===> 4.9-RELEASE and 5.2-RELEASE or use the -stable or -current tree."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options (or make config):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CLIENT_ONLY=yes		if you only want the file daemon."
.if !defined(WITH_MYSQL)
	@${ECHO_MSG} "  WITH_MYSQL=yes		if you want MySQL instead of SqLite as the database."
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> Using MySQL as the bacula database."
.endif
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
	# don't know how to make it better
	${RM} -f ${PREFIX}/etc/rc.d/bacula.sh.sample
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
		${INSTALL_DATA} ${FILESDIR}/bacula-barcodes ${PREFIX}/etc ; \
		${ECHO_CMD} "etc/bacula-barcodes" >> ${TMPPLIST}; \
	fi
	if [ -f ${PREFIX}/etc/console.conf.new ]; then \
		${ECHO_CMD} "etc/console.conf.new" >> ${TMPPLIST}; \
	elif [ -f ${PREFIX}/etc/console.conf ]; then \
		${ECHO_CMD} "etc/console.conf" >> ${TMPPLIST}; \
	fi
	# chmod of smtp program so bacula can use it with dropped down permissions
	${CHMOD} o+x ${PREFIX}/sbin/smtp
	${CHOWN} -R bacula:bacula ${PREFIX}/share/bacula
.endif
	# Install leaves existing conf files untouched. Respect this here!
	for na in sd fd dir; do \
		if [ -f ${PREFIX}/etc/bacula-$$na.conf.new ]; then \
			${ECHO_CMD} "etc/bacula-$$na.conf.new" >> ${TMPPLIST}; \
		elif [ -f ${PREFIX}/etc/bacula-$$na.conf ]; then \
			${ECHO_CMD} "etc/bacula-$$na.conf" >> ${TMPPLIST}; \
		fi \
	done; \

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html-manual
	${INSTALL_DATA} ${WRKSRC}/doc/bacula.pdf ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} html-manual | \
		${CPIO} -pdm -L -R root:wheel ${DOCSDIR}
.endif

# Inform user after install about important things ....
.if !defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "*******************************************************"
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "An auto-changer manipulation script based on FreeBSDs"
	@${ECHO_MSG} "chio command is included and installed at"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  ${PREFIX}/sbin/chio-bacula"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please have a look at it if you want to use an"
	@${ECHO_MSG} "auto-changer. You have to configure the usage in"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  ${PREFIX}/etc/bacula-dir.conf"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take care of correct permissions for changer and"
	@${ECHO_MSG} "tape device (e.g. /dev/ch0 and /dev/n[r]sa0) i.e."
	@${ECHO_MSG} "they must be accesable by user bacula."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Due to lack of some features in the FreeBSD tape driver"
	@${ECHO_MSG} "implemtation you MUST add some OS dependent options to"
	@${ECHO_MSG} "the bacula-sd.conf file:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  Backward Space Record = no;"
	@${ECHO_MSG} "  Hardware End of Medium = no;"
	@${ECHO_MSG} "  Fast Forward Space File = no;"
	@${ECHO_MSG} "  BSF at EOM = yes;"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "It is also important that all the scripts accessed"
	@${ECHO_MSG} "by RunBeforeJob and RunAfterJob could be executed by"
	@${ECHO_MSG} "the user bacula, too."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*******************************************************"
.endif

.include <bsd.port.post.mk>
