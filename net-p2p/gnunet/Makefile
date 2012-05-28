# ex:ts=8
# Ports collection makefile for:	GNUnet
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnunet
DISTVERSION=	0.9.2
CATEGORIES=	net-p2p ipv6 security
MASTER_SITES=	GNU

MAINTAINER=	bf@FreeBSD.org
COMMENT=	An anonymous, distributed, reputation-based network

LICENSE=	GPLv3

LIB_DEPENDS=	unistring:${PORTSDIR}/devel/libunistring \
		curl:${PORTSDIR}/ftp/curl \
		glpk:${PORTSDIR}/math/glpk \
		gmp:${PORTSDIR}/math/gmp \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		extractor:${PORTSDIR}/textproc/libextractor

OPTIONS=	HTTP	"Enable HTTP transport via libmicrohttpd" off \
		MYSQL	"Use MySQL for the datastore and datacache" off \
		NLS	"Enable Native Language support" on \
		PGSQL	"Use PostgreSQL for the datastore and datacache" off \
		SQLITE	"Use SQLite for the datastore and datacache" on

USE_AUTOTOOLS=	libltdl libtool
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS =	--with-daemon-home-dir=${GNUNET_DAEMON_DIR} \
			--with-daemon-config-dir=${PREFIX}/etc \
			--with-extractor=${LOCALBASE} \
			--with-libcurl=${LOCALBASE} \
			--with-libgcrypt-prefix=${LOCALBASE} \
			--with-libunistring-prefix=${LOCALBASE} \
			--with-ltdl-include=${LOCALBASE}/include \
			--with-ltdl-lib=${LOCALBASE}/lib

GROUPS =	gnunet
USERS=		gnunet

MAN1=	gnunet-arm.1 gnunet-directory.1 gnunet-download.1 \
	gnunet-download-manager.1 gnunet-fs.1 gnunet-nat-server.1 \
	gnunet-peerinfo.1 gnunet-pseudonym.1 gnunet-publish.1 \
	gnunet-search.1 gnunet-statistics.1 gnunet-transport.1 \
	gnunet-unindex.1 gnunet-vpn.1

GNUNET_DAEMON_DIR?=		/var/lib/gnunet
PLIST_SUB=	GNUNET_DAEMON_DIR=${GNUNET_DAEMON_DIR}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	gnunet_janitor.py gnunet_pyexpect.py hostlist.cgi hostlist.php report.sh
.endif

.if defined(WITH_HTTP)
BROKEN =	WITH_HTTP requires libmicrohttpd 0.9.18 or higher
LIB_DEPENDS+=		microhttpd:${PORTSDIR}/www/libmicrohttpd
CONFIGURE_ARGS+=	--with-microhttpd=${LOCALBASE}
PLIST_SUB+=		HTTP=""
.else
CONFIGURE_ARGS+=	--without-microhttpd
PLIST_SUB+=		HTTP="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB+=		MYSQL=""
.else
.if !(defined(WITH_PGSQL) || defined(WITH_SQLITE))
IGNORE =	define at least one of WITH_MYSQL, WITH_PGSQL, and WITH_SQLITE
.endif
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
PLIST_SUB+=		PGSQL=""
.else
CONFIGURE_ARGS+=	--without-postgres
PLIST_SUB+=		PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=		yes
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
PLIST_SUB+=		SQLITE=""
.else
CONFIGURE_ARGS+=	--without-sqlite
PLIST_SUB+=		SQLITE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|postgresql/||g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/datacache/plugin_datacache_postgres.c \
		${WRKSRC}/src/datastore/plugin_datastore_postgres.c
	@${REINPLACE_CMD} \
	-e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/pkgconfig/Makefile.in

post-install:
	@${PRINTF} "%s\n%s\n" "[PATHS]" "SERVICEHOME = ${GNUNET_DAEMON_DIR}" \
	> ${PREFIX}/etc/gnunet.conf.sample
.if !exists(${PREFIX}/etc/gnunet.conf)
	@${CP} ${PREFIX}/etc/gnunet.conf.sample ${PREFIX}/etc/gnunet.conf
.endif
.if !exists(${GNUNET_DAEMON_DIR})
	@${INSTALL} -d -o gnunet -g gnunet -m 700 ${GNUNET_DAEMON_DIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/contrib/timeout_watchdog ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/contrib; ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
