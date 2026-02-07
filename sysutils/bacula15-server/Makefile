PORTNAME=	bacula
DISTVERSION=	15.0.3
CATEGORIES?=	sysutils
MASTER_SITES=	SF/bacula/bacula/${DISTVERSION}
PKGNAMEPREFIX?=	#
PKGNAMESUFFIX?=	15-server

MAINTAINER=	dvl@FreeBSD.org
COMMENT?=	Network backup solution (server)
WWW=		https://www.bacula.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		cpe libtool localbase python:env readline shebangfix ssl

SHEBANG_FILES=	scripts/get_malware_abuse.ch scripts/key-manager.py.in \
		scripts/md5tobase64.py src/cats/make_catalog_backup.pl.in
#scripts/baculabackupreport.in

CONFLICTS?=	bacula13-server bacula11-server bacula9-server

LIB_DEPENDS+=	liblzo2.so:archivers/lzo2 \
		libzstd.so:archivers/zstd

USERS=		bacula
GROUPS=		${USERS}

LIB_VERSION=	${DISTVERSION}

PLIST_SUB+=	LIB_VERSION=${LIB_VERSION}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_LDCONFIG=	yes

OPTIONS_DEFINE?=	IPV6 MTX NLS S3
MTX_DESC=		Install mtx for control of autochanger devices
S3_DESC=		Install S3 plugin

.if ${PKGNAMESUFFIX} == "15-server"
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MYSQL PGSQL SQLITE3
OPTIONS_DEFAULT+=	PGSQL
.endif

OPTIONS_SUB=	yes

.if ${PKGNAMESUFFIX} == "15-client" || ${PKGNAMESUFFIX} == "15-server" #Till end of the file

.if !defined(WITH_CLIENT_ONLY)
LIB_DEPENDS+=	libbac-${LIB_VERSION}.so:sysutils/bacula15-client
USE_RC_SUBR?=	bacula_dir bacula_sd
.endif

.if defined(WITH_CLIENT_ONLY)
SUB_FILES+=	pkg-deinstall.client pkg-install.client pkg-message.client
.else
SUB_FILES+=	pkg-message.server
.endif

CONFIGURE_ARGS+=	--disable-conio \
			--enable-batch-insert \
			--enable-smartalloc \
			--sysconfdir=${ETCDIR} \
			--with-baseport=9101 \
			--with-db-name=bacula \
			--with-db-user=bacula \
			--with-dump-email=root@localhost \
			--with-job-email=root@localhost \
			--with-logdir=/var/log \
			--with-plugindir=${PREFIX}/lib \
			--with-readline=${LOCALBASE} \
			--with-sbin-perm=755 \
			--with-scriptdir=${PREFIX}/share/${PORTNAME} \
			--with-tcp-wrappers=/usr/lib \
			--with-working-dir=${BACULA_DIR}

.if defined(WITH_CLIENT_ONLY)
CONFIGURE_ARGS+=	--with-fd-group=wheel \
			--with-fd-user=root
.else
CONFIGURE_ARGS+=	--with-dir-group=${BACULA_GROUP} \
			--with-dir-user=${BACULA_USER} \
			--with-sd-group=operator \
			--with-sd-user=${BACULA_USER}
.endif

# The user/group IDs below are registered, see
# http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/book.html#users-and-groups
#
BACULA_USER?=	bacula
BACULA_GROUP?=	${BACULA_USER}
BACULA_UID?=	bacula
BACULA_GID?=	${BACULA_UID}
BACULA_DIR?=	/var/db/bacula

PLIST_SUB+=	BACULA_DIR=${BACULA_DIR}

SUB_LIST+=	BACULA_DIR=${BACULA_DIR} \
		BACULA_GID=${BACULA_GID} \
		BACULA_GROUP=${BACULA_GROUP} \
		BACULA_UID=${BACULA_UID} \
		BACULA_USER=${BACULA_USER}

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

# Client only or full server version
.if defined(WITH_CLIENT_ONLY)
CONFFILES=		fd
CONFIGURE_ARGS+=	--enable-client-only

PKGDEINSTALL=	${FILESDIR}/pkg-deinstall.client
PKGINSTALL=	${FILESDIR}/pkg-install.client
.else
# Server only Options
CONFFILES=	sd dir
# Server default database

MYSQL_CONFIGURE_ON=	--with-mysql=yes
MYSQL_USES=		mysql
MYSQL_SUB_LIST=		REQ_MYSQL=mysql
MYSQL_SUB_LIST_OFF=	REQ_MYSQL=""
SQLITE3_CONFIGURE_ON=	--with-sqlite3=yes
SQLITE3_USES=		sqlite:3
PGSQL_CONFIGURE_ON=	--with-postgresql=yes
PGSQL_USES=		pgsql
PGSQL_SUB_LIST=		REQ_PGSQL=postgresql
PGSQL_SUB_LIST_OFF=	REQ_PGSQL=""

MTX_RUN_DEPENDS=	${LOCALBASE}/sbin/mtx:misc/mtx

.endif

S3_CONFIGURE_ARGS=	--enable-s3
S3_LIB_DEPENDS=		libs3.so:sysutils/bacula-libs3

.include <bsd.port.pre.mk>

.if defined(WITH_CLIENT_ONLY)
MP8+=		bacula.8 bacula-fd.8 bconsole.8
.else
MP8+=		bacula-dir.8 bacula-sd.8 bcopy.8 bextract.8 bls.8 bscan.8 \
		btape.8 btraceback.8 dbcheck.8 bwild.8 bregex.8
MP1+=		bsmtp.1 bacula-tray-monitor.1
.endif

MAKE_ENV+=	MAN1="${MP1}" \
		MAN8="${MP8}"

post-patch:
# This port does not install docs.  See bacula-docs for that
	@${REINPLACE_CMD} -e '/docdir/d' ${WRKSRC}/Makefile.in
# Change $(ECHO) to echo in some Makefile.in files
	@${REINPLACE_CMD} -e 's|$$(ECHO)|echo|g'  \
		${WRKSRC}/src/filed/Makefile.in   \
		${WRKSRC}/src/console/Makefile.in \
		${WRKSRC}/src/cats/Makefile.in    \
		${WRKSRC}/src/dird/Makefile.in    \
		${WRKSRC}/src/stored/Makefile.in  \
		${WRKSRC}/src/tools/Makefile.in

# Default bconsole.conf is in ${ETCDIR}
	@${REINPLACE_CMD} -e 's|./bconsole.conf|${ETCDIR}/bconsole.conf|g' ${WRKSRC}/src/console/console.c
	@${REINPLACE_CMD} -e 's|^MAN8 =|MAN8 ?=|g' -e 's|^MAN1 =|MAN1 ?=|g' ${WRKSRC}/manpages/Makefile.in
.if defined(WITH_CLIENT_ONLY)
# In client port only install startup script out of script dir (see below post-install)
# Dont mkdir ${PREFIX}/share/bacula cause it's empty
	@${REINPLACE_CMD} -e 's|^\(fd_subdirs = .*\)scripts\(.*\)|\1\2|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(.*$${MKDIR} $${DESTDIR}$${scriptdir}\)|#\1|g' ${WRKSRC}/Makefile.in
.else
# In server port don't install filed
	@${REINPLACE_CMD} -e '/^fd_subdirs = /s|src/filed||' -e 's|src/console||' \
		${WRKSRC}/Makefile.in
.endif

.if !target(post-install)
post-install:
.if defined(WITH_CLIENT_ONLY)
	${MV} ${STAGEDIR}${ETCDIR}/bconsole.conf ${STAGEDIR}${ETCDIR}/bconsole.conf.sample
	${INSTALL_DATA} ${WRKSRC}/examples/sample-query.sql ${STAGEDIR}${LOCALBASE}/share/bacula/query.sql.sample
.else
	${INSTALL_SCRIPT} ${FILESDIR}/chio-bacula ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/bacula-barcodes ${STAGEDIR}${ETCDIR}/bacula-barcodes.sample
# bacula-dir attempts to install query.sql as bpart of bacula-server, but that should only installed by bacula-client.
	${RM} ${STAGEDIR}${LOCALBASE}/share/bacula/query.sql

#the following are installed by the -CLIENT port, and I (ler@lerctr.org)
#don't know how to remove them from being built for the -SERVER port.
	${RM} ${STAGEDIR}${LOCALBASE}/lib/bpipe-fd.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbac-${LIB_VERSION}.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbac.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbaccfg-${LIB_VERSION}.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbaccfg.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbacfind-${LIB_VERSION}.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbacfind.so
.endif
	for na in ${CONFFILES}; do \
		${MV} ${STAGEDIR}${ETCDIR}/bacula-$$na.conf ${STAGEDIR}${ETCDIR}/bacula-$$na.conf.sample; \
	done
.endif
.else
.include "${MASTERDIR}/Makefile.common"
.endif # 15-client and 15-server are defined

.include <bsd.port.post.mk>
