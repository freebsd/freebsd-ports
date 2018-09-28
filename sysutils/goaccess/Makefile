# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	goaccess
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://tar.goaccess.io/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Real-time Apache web log analyzer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		alias pkgconfig ncurses

CFLAGS+=	-I${NCURSESINC} -I${LOCALBASE}/include
LDFLAGS+=	-L${NCURSESLIB} -L${LOCALBASE}/lib

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS DEBUG UTF8
OPTIONS_DEFAULT=	GEOIP UTF8
OPTIONS_RADIO=	GEOIPDB TOKYOCABINET
OPTIONS_RADIO_GEOIPDB=	GEOIP GEOIP2
OPTIONS_RADIO_TOKYOCABINET=	TOKYOCABINET_BTREE TOKYOCABINET_MHASH

GEOIPDB_DESC=	GeoIP IP location support
GEOIP_DESC=	Legacy/free database format
GEOIP2_DESC=	New/paid database format

DEBUG_CONFIGURE_ON=	--enable-debug
UTF8_CONFIGURE_ON=	--enable-utf8

GEOIP_CONFIGURE_ON=	--enable-geoip=legacy
GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP
GEOIP2_CONFIGURE_ON=	--enable-geoip=mmdb
GEOIP2_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

TOKYOCABINET_DESC=	Tokyo Cabinet support
TOKYOCABINET_BTREE_DESC=	Storage using on-disk B+ Tree
TOKYOCABINET_MHASH_DESC=	Storage using on-memory hash database
TOKYOCABINET_BTREE_CONFIGURE_ON=	--enable-tcb=btree
TOKYOCABINET_MHASH_CONFIGURE_ON=	--enable-tcb=memhash
TOKYOCABINET_BTREE_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet
TOKYOCABINET_HASH_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
