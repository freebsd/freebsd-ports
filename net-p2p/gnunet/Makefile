# ex:ts=8
# Ports collection makefile for:	GNUnet
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnunet
DISTVERSION=	0.9.3
PORTREVISION=	1
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

OPTIONS_DEFINE =	HTTP

HTTP_DESC=	Enable HTTP transport via libmicrohttpd
MYSQL_DESC=	Use MySQL for the data store and cache
PGSQL_DESC=	Use PostgreSQL for the data store and cache
SQLITE_DESC=	Use SQLite for the data store and cache

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE

OPTIONS_DEFAULT=	SQLITE

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

MAN1=	gnunet-arm.1 gnunet-core.1 gnunet-directory.1 gnunet-download.1 \
	gnunet-download-manager.1 gnunet-fs.1 gnunet-gns.1 gnunet-namestore.1 \
	gnunet-nat-server.1 gnunet-peerinfo.1 gnunet-pseudonym.1 \
	gnunet-publish.1 gnunet-rsa.1 gnunet-search.1 gnunet-statistics.1 \
	gnunet-transport.1 gnunet-unindex.1 gnunet-vpn.1

#If a non-default GNUNET_DAEMON_DIR is defined, the home directory
#of the gnunet user may need to be adjusted -- e.g., via:
#pw usermod gnunet -d $GNUNET_DAEMON_DIR
GNUNET_DAEMON_DIR?=		/var/lib/gnunet
PLIST_SUB=	GNUNET_DAEMON_DIR=${GNUNET_DAEMON_DIR}
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	gnunet_janitor.py gnunet_pyexpect.py hostlist.cgi hostlist.php \
report.sh
.endif

.if ${PORT_OPTIONS:MHTTP}
BROKEN =	WITH_HTTP requires libmicrohttpd 0.9.18 or higher
LIB_DEPENDS+=		microhttpd:${PORTSDIR}/www/libmicrohttpd
CONFIGURE_ARGS+=	--with-microhttpd=${LOCALBASE}
PLIST_SUB+=		HTTP=""
.else
CONFIGURE_ARGS+=	--without-microhttpd
PLIST_SUB+=		HTTP="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB+=		MYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
PLIST_SUB+=		PGSQL=""
.else
CONFIGURE_ARGS+=	--without-postgres
PLIST_SUB+=		PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
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
		${WRKSRC}/gnunet_config.h \
		${WRKSRC}/src/datacache/plugin_datacache_postgres.c \
		${WRKSRC}/src/datastore/plugin_datastore_postgres.c \
		${WRKSRC}/src/include/gnunet_postgres_lib.h
	@${REINPLACE_CMD} \
	-e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/pkgconfig/Makefile.in

post-install:
	@${PRINTF} "%s\n%s\n%s\n" "[PATHS]" \
	"SERVICEHOME = ${GNUNET_DAEMON_DIR}" \
	"DEFAULTCONFIG = ${PREFIX}/etc/gnunet.conf" \
	> ${PREFIX}/etc/gnunet.conf.sample
.if !exists(${PREFIX}/etc/gnunet.conf)
	@${CP} ${PREFIX}/etc/gnunet.conf.sample ${PREFIX}/etc/gnunet.conf
.endif
.if !exists(${GNUNET_DAEMON_DIR})
	@${INSTALL} -d -o gnunet -g gnunet -m 700 ${GNUNET_DAEMON_DIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/contrib/timeout_watchdog ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/contrib; ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.mk>
