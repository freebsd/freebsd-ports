# New ports collection makefile for:	bacula
# Date created:				24 February 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
PORTVERSION=	1.32b
#PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bacula

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE
COMMENT=	The network backup solution

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcp-wrappers=/usr/lib \
		--enable-smartalloc \
		--with-working-dir=/var/db/bacula

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

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_CLIENT_ONLY)
	@${ECHO_MSG} "=======> ATTENTION <======="
	@${ECHO_MSG} "===> Note that there is a pthreads problem, which leads to the loss of 500kB"
	@${ECHO_MSG} "===> of data at the end of an tape. This is corrected in the upcoming"
	@${ECHO_MSG} "===> 4.9-RELEASE and 5.2-RELEASE or use the -stable or -current tree."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CLIENT_ONLY=yes	if you only want the file daemon."
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

post-install:
.if defined(WITH_CLIENT_ONLY)
	# don't know how to make it better
	${RM} -f ${PREFIX}/etc/rc.d/bacula.sh.sample
.else
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
		cpio -pdm -L -R root:wheel ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
