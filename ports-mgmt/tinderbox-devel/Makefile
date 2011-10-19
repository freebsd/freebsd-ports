# Ports collection makefile for:	misc/tinderbox
# Whom:			Edwin Groothuis <edwin@mavetju.org>
# Date created:		31 december 2005
#
# $FreeBSD$

PORTNAME=	tinderbox
DISTVERSION=	3.4${SNAP}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://tinderbox.marcuscom.com/ \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Port build tinderbox system, devel version

CONFLICTS=	tinderbox-[0-9]*

OPTIONS=	PGSQL "With pgsql" Off \
		MYSQL "With mysql" On \
		WEBUI   "Install web interface" On \
		APACHE "Use Apache for web interface" On \
		HIAWATHA "Use Hiawatha for web interface" Off \
		LIGHTTPD "Use LightHTTPD for web interface" Off \
		CHECK_FOR_ROOT "Check if ./tc is run by uid 0" On \
		EMAILS "Support for build failure/completion emails" On \
		LSOF "For killMountProcesses() when using nullfs" On \
		LOG_COMPRESS "Support bzip'ing the logs" On \
		PARALLEL "Enable PARALLEL extra patch" On \
#		TMPFS "Enable TMPFS extra patch" Off

NO_BUILD=	yes
WANT_PERL=	yes
SUB_FILES=	pkg-message

SNAP=		.r2
#SNAP=		-20110101 # 22:28:07 UTC

MAN1=		tc-configCcache.1 tc-configDistfile.1 tc-configGet.1 \
		tc-configJail.1 tc-configTinderd.1 tc-init.1

.include <bsd.port.pre.mk>

.if !defined(WITH_PGSQL) && defined(WITHOUT_MYSQL)
IGNORE=	is useless without a database. Please (re)run 'make config' and choose one of PGSQL and MYSQL
.endif

.if defined(WITH_WEBUI)
WANT_PHP_WEB=	yes
USE_PHP=	session
PLIST_SUB+=	WEBUI=""
.else
PLIST_SUB+=	WEBUI="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.if defined(WITH_WEBUI)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/pgsql.php:${PORTSDIR}/databases/pear-MDB2_Driver_pgsql
USE_PHP+=	pgsql
.endif
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if !defined(WITHOUT_MYSQL)
.if defined(WITH_WEBUI)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/mysql.php:${PORTSDIR}/databases/pear-MDB2_Driver_mysql
USE_PHP+=	mysql
.endif
USE_MYSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER}
.endif

.if !defined(WITHOUT_APACHE) && defined(WITH_WEBUI)
USE_APACHE=	13+
.elif defined(WITH_LIGHTTPD) && defined(WITH_WEBUI)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.elif defined(WITH_HIAWATHA) && defined(WITH_WEBUI)
RUN_DEPENDS+=	hiawatha:${PORTSDIR}/www/hiawatha
.endif

.if defined(WITH_EMAILS)
RUN_DEPENDS+=	${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net
.endif

.if defined(WITH_LSOF)
RUN_DEPENDS+=	lsof:${PORTSDIR}/sysutils/lsof
.endif

.if defined(WITH_LOG_COMPRESS)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Compress/Bzip2.pm:${PORTSDIR}/archivers/p5-Compress-Bzip2
.endif

.if defined(WITH_TMPFS) && defined(WITH_PARALLEL)
EXTRA_PATCHES+=		${FILESDIR}/extra-tmpfs_para.patch
.elif defined(WITH_TMPFS) && !defined(WITH_PARALLEL)
EXTRA_PATCHES+=		${FILESDIR}/extra-tmpfs.patch
.elif defined(WITH_PARALLEL) && !defined(WITH_TMPFS)
EXTRA_PATCHES+=		${FILESDIR}/extra-parallel.patch
.endif

pre-everything::
.if (!defined(WITHOUT_APACHE) || defined(WITH_LIGHTTPD) || defined(WITH_HIAWATHA)) && !defined(WITH_WEBUI)
	@${ECHO_CMD} "It doesn't make sense to depend on Apache, Hiawatha or LightHTTPD if not using the WebUI."
	@${FALSE}
.endif

.if !defined(WITH_WEBUI)
post-extract:
	@${RM} -R ${WRKSRC}/webui
.endif

post-patch:
.ifdef WITHOUT_CHECK_FOR_ROOT
	${REINPLACE_CMD} -e 's/^if \[ `id -u` != 0 \]; then/if false; then/' \
		${WRKSRC}/tc
.endif
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

.include <bsd.port.post.mk>
