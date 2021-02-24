# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bacula
PORTVERSION=	11.0.1
CATEGORIES?=	sysutils
MASTER_SITES=	SF/bacula/bacula/${PORTVERSION}
PKGNAMEPREFIX?=	#
PKGNAMESUFFIX?=	11-server

MAINTAINER=	dvl@FreeBSD.org
COMMENT?=	Network backup solution (server)

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		libtool readline shebangfix ssl
SHEBANG_FILES=	src/cats/make_catalog_backup.pl.in

CONFLICTS?=	bacula9-server-* bacula5-server-* bacula-server-*

LIB_DEPENDS+=	liblzo2.so:archivers/lzo2

USERS=		bacula
GROUPS=		${USERS}

PLIST_SUB+=	LIB_VERSION=${PORTVERSION}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I/usr/include/readline -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE?=	MTX NLS IPV6
MTX_DESC=		Install mtx for control of autochanger devices

.if ${PKGNAMESUFFIX} == "11-server"
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	SQLITE3 MYSQL PGSQL
OPTIONS_DEFAULT+=	PGSQL
.endif

OPTIONS_SUB=		yes

.if ${PKGNAMESUFFIX} == "11-client" || ${PKGNAMESUFFIX} == "11-server"  #Till end of the file

.if !defined(WITH_CLIENT_ONLY)
LIB_DEPENDS+=	libbac-${PORTVERSION}.so:sysutils/bacula11-client
USE_RC_SUBR?=	bacula-dir bacula-sd
.endif

.if defined(WITH_CLIENT_ONLY)
SUB_FILES+=	pkg-install.client pkg-deinstall.client pkg-message.client
.else
SUB_FILES+=	pkg-message.server
.endif

CONFIGURE_ARGS+=--with-tcp-wrappers=/usr/lib \
		--enable-smartalloc \
		--sysconfdir=${ETCDIR} \
		--with-working-dir=${BACULA_DIR} \
		--with-scriptdir=${PREFIX}/share/${PORTNAME} \
		--disable-conio \
		--enable-batch-insert \
		--with-plugindir=${PREFIX}/lib \
		--with-dump-email=root@localhost \
		--with-job-email=root@localhost \
		--with-db-name=bacula \
		--with-sbin-perm=755 \
		--with-db-user=bacula \
		--with-logdir=/var/log \
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
# http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/book.html#users-and-groups
#
BACULA_USER?=	bacula
BACULA_GROUP?=	${BACULA_USER}
BACULA_UID?=	bacula
BACULA_GID?=	${BACULA_UID}
BACULA_DIR?=	/var/db/bacula

PLIST_SUB+=	BACULA_DIR=${BACULA_DIR}

SUB_LIST=	BACULA_USER=${BACULA_USER} \
		BACULA_GROUP=${BACULA_GROUP} \
		BACULA_UID=${BACULA_UID} \
		BACULA_GID=${BACULA_GID} \
		BACULA_DIR=${BACULA_DIR}

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

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

MYSQL_CONFIGURE_ON=	--with-mysql=yes
MYSQL_USES=		mysql
SQLITE3_CONFIGURE_ON=	--with-sqlite3=yes
SQLITE3_USES=		sqlite:3
PGSQL_CONFIGURE_ON=	--with-postgresql=yes
PGSQL_USES=		pgsql

MTX_RUN_DEPENDS=	${LOCALBASE}/sbin/mtx:misc/mtx

.endif

.include <bsd.port.pre.mk>

.if ${readline_ARGS} == "port"
readline_CONFIGURE=	${LOCALBASE}
.else
readline_CONFIGURE=	yes
.endif

# if IPv6 is not in the kernel, it generates many errors
.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--disable-ipv6
.endif

CONFIGURE_ARGS+=	--with-readline=${readline_CONFIGURE}

.if defined(WITH_CLIENT_ONLY)
MP8+=	bacula.8 bacula-fd.8 bconsole.8
.else
MP8+=	bacula-dir.8 bacula-sd.8 bcopy.8 bextract.8 bls.8 bscan.8 \
	btape.8 btraceback.8 dbcheck.8 bwild.8 bregex.8
MP1+=	bsmtp.1 bacula-tray-monitor.1
.endif

MAKE_ENV+=	MAN8="${MP8}" MAN1="${MP1}"

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
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbac-${PORTVERSION}.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbac.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbaccfg-${PORTVERSION}.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbaccfg.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbacfind-${PORTVERSION}.so
	${RM} ${STAGEDIR}${LOCALBASE}/lib/libbacfind.so
.endif
	for na in ${CONFFILES}; do \
		${MV} ${STAGEDIR}${ETCDIR}/bacula-$$na.conf ${STAGEDIR}${ETCDIR}/bacula-$$na.conf.sample; \
	done
.endif
.else
.include "${MASTERDIR}/Makefile.common"
.endif # 11-client and 11-server are defined

.include <bsd.port.post.mk>
