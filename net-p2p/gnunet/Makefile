# Created by: ijliao
# $FreeBSD$

PORTNAME=	gnunet
PORTVERSION=	0.10.1
PORTREVISION=	2
CATEGORIES=	net-p2p ipv6 security
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anonymous, distributed, reputation-based network

LICENSE=	GPLv3

LIB_DEPENDS=	libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libpulse.so:audio/pulseaudio \
		libltdl.so:devel/libltdl \
		libunistring.so:devel/libunistring \
		libidn.so:dns/libidn \
		libglpk.so:math/glpk \
		libgmp.so:math/gmp \
		libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libextractor.so:textproc/libextractor

USES=		gmake iconv libtool pathfix pkgconfig
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--with-extractor=${LOCALBASE} \
		--with-gnutls=${LOCALBASE} \
		--with-libgcrypt-prefix=${LOCALBASE} \
		--with-libunistring-prefix=${LOCALBASE} \
		--with-ltdl=${LOCALBASE} \
		--with-nssdir=no
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GROUPS=		gnunet
USERS=		gnunet

SUB_FILES=	pkg-install pkg-deinstall pkg-message
SUB_LIST=	GNUNET_DAEMON_DIR="${GNUNET_DAEMON_DIR}"

PLIST_SUB=	GNUNET_DAEMON_DIR="${GNUNET_DAEMON_DIR}"

OPTIONS_DEFINE=		DOCS EXAMPLES HTTP NLS
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE
OPTIONS_SUB=		yes

HTTP_DESC=		Enable HTTP transport via libmicrohttpd
HTTP_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
HTTP_CONFIGURE_ON=	--with-microhttpd=${LOCALBASE}
HTTP_CONFIGURE_OFF=	--without-microhttpd
MYSQL_DESC=		Use MySQL for the data store and cache
MYSQL_USE=		mysql=yes
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
NLS_USES=		gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls
PGSQL_DESC=		Use PostgreSQL for the data store and cache
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgres=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-postgres
SQLITE_DESC=		Use SQLite for the data store and cache
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}
SQLITE_CONFIGURE_OFF=	--without-sqlite

#If a non-default GNUNET_DAEMON_DIR is defined, the home directory
#of the gnunet user may need to be adjusted -- e.g., via:
#pw usermod gnunet -d $GNUNET_DAEMON_DIR
GNUNET_DAEMON_DIR?=		/var/lib/gnunet

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am/s|install-docDATA||' ${WRKSRC}/Makefile.in
.for i in configure gnunet_config.h \
	src/datacache/plugin_datacache_postgres.c \
	src/datastore/plugin_datastore_postgres.c \
	src/include/gnunet_postgres_lib.h
	@${REINPLACE_CMD} -e \
		's|postgresql/||g' ${WRKSRC}/${i}
.endfor

post-build:
	@${PRINTF} "%s\n%s\n%s\n" "[PATHS]" \
	"SERVICEHOME = ${GNUNET_DAEMON_DIR}" \
	"DEFAULTCONFIG = ${PREFIX}/etc/gnunet.conf" \
	> ${WRKDIR}/gnunet.conf.sample

post-install:
	(cd ${WRKSRC}/contrib && ${INSTALL_PROGRAM} timeout_watchdog \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKDIR} && ${INSTALL_DATA} gnunet.conf.sample \
		${STAGEDIR}${PREFIX}/etc)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in gnunet_janitor.py gnunet_pyexpect.py report.sh
	(cd ${WRKSRC}/contrib && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
