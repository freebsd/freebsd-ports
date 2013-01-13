# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	tinderbox
DISTVERSION=	4.0.0.b2
PORTEPOCH=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://tinderbox.marcuscom.com/ \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Port build tinderbox system, devel version

CONFLICTS=	tinderbox-[0-9]*

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	PGSQL MYSQL SQLITE

OPTIONS_RADIO=		WEB
OPTIONS_RADIO_WEB=	APACHE HIAWATHA LIGHTTPD

OPTIONS_DEFINE=		CHECK_FOR_ROOT EMAILS LSOF LOG_COMPRESS PARALLEL \
			TMPFS

CHECK_FOR_ROOT_DESC=	Check if ./tc is run by uid 0
EMAILS_DESC=		Support for build failure/completion emails
LSOF_DESC=		For killMountProcesses() when using nullfs
LOG_COMPRESS_DESC=	Support bzip'ing the logs
PARALLEL_DESC=		Apply PARALLEL extra patch
TMPFS_DESC=		Apply TMPFS extra patch
HIAWATHA_DESC=		Hiawatha server

OPTIONS_DEFAULT=	MYSQL APACHE CHECK_FOR_ROOT EMAILS LSOF \
			LOG_COMPRESS PARALLEL

NO_BUILD=	yes
WANT_PERL=	yes
SUB_FILES=	pkg-message

#SNAP=		.r3-20120404
#SNAP=		-20110101 # 22:28:07 UTC

MAN1=		tc-configCcache.1 tc-configDistfile.1 tc-configGet.1 \
		tc-configJail.1 tc-configTinderd.1 tc-init.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE} || ${PORT_OPTIONS:MHIAWATHA} || ${PORT_OPTIONS:MLIGHTTPD}
WEBUI=		yes
.endif

.if defined(WEBUI)
WANT_PHP_WEB=	yes
USE_PHP=	session
PLIST_SUB+=	WEBUI=""
.else
PLIST_SUB+=	WEBUI="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
.if defined(WEBUI)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/pgsql.php:${PORTSDIR}/databases/pear-MDB2_Driver_pgsql
USE_PHP+=	pgsql
.endif
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MMYSQL}
.if defined(WEBUI)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/mysql.php:${PORTSDIR}/databases/pear-MDB2_Driver_mysql
USE_PHP+=	mysql
.endif
USE_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MSQLITE}
.if defined(WEBUI)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/sqlite.php:${PORTSDIR}/databases/pear-MDB2_Driver_sqlite
USE_PHP+=	sqlite
.endif
RUN_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.elif ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.elif ${PORT_OPTIONS:MHIAWATHA}
RUN_DEPENDS+=	hiawatha:${PORTSDIR}/www/hiawatha
.endif

.if ${PORT_OPTIONS:MEMAILS}
RUN_DEPENDS+=	p5-Net>=0:${PORTSDIR}/net/p5-Net
.endif

.if ${PORT_OPTIONS:MLSOF}
RUN_DEPENDS+=	lsof:${PORTSDIR}/sysutils/lsof
.endif

.if ${PORT_OPTIONS:MLOG_COMPRESS}
RUN_DEPENDS+=	p5-Compress-Bzip2>=0:${PORTSDIR}/archivers/p5-Compress-Bzip2
.endif

.if ${PORT_OPTIONS:MTMPFS} && ${PORT_OPTIONS:MPARALLEL}
EXTRA_PATCHES+=		${FILESDIR}/extra-tmpfs_para.patch
.elif ${PORT_OPTIONS:MTMPFS}
EXTRA_PATCHES+=		${FILESDIR}/extra-tmpfs.patch
.elif ${PORT_OPTIONS:MPARALLEL}
EXTRA_PATCHES+=		${FILESDIR}/extra-parallel.patch
.endif

.if ! defined(WEBUI)
post-extract:
	@${RM} -R ${WRKSRC}/webui
.endif

post-patch:
.if ! ${PORT_OPTIONS:MCHECK_FOR_ROOT}
	${REINPLACE_CMD} -e 's/^if \[ `id -u` != 0 \]; then/if false; then/' \
		${WRKSRC}/tc
.endif
	${REINPLACE_CMD} -e 's/.set_rcvar./tinderd_enable/' \
		${WRKSRC}/etc/rc.d/tinderd
	@cd ${WRKSRC} && ${FIND} -E . -regex '.*(orig|bak)' -exec ${RM} {} \;

do-install:
	@${MKDIR} ${PREFIX}/tinderbox/scripts
	@${ECHO_CMD} "Installing man pages ..."
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1 && \
		cd ${WRKSRC} && ${RM} -r ${WRKSRC}/man
	@${ECHO_CMD} "Installing rc script ..."
	${INSTALL_SCRIPT} ${WRKSRC}/etc/rc.d/tinderd ${PREFIX}/etc/rc.d/${PORTNAME}
	@${ECHO_CMD} "Installing tinderbox ..."
	${CP} -R ${WRKSRC}/* ${PREFIX}/tinderbox/scripts
	@${ECHO_CMD} "All Done"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
