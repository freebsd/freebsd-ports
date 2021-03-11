# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	goaccess
PORTVERSION=	1.4.6
CATEGORIES=	sysutils
MASTER_SITES=	http://tar.goaccess.io/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Real-time Apache web log analyzer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		alias compiler:c11 pkgconfig ncurses
USE_RC_SUBR=	goaccess

INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes

CFLAGS+=	-I${NCURSESINC} -I${LOCALBASE}/include
LDFLAGS+=	-L${NCURSESLIB} -L${LOCALBASE}/lib

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS DEBUG GEOIP2 NLS SSL UTF8
OPTIONS_DEFAULT=	GEOIP2 SSL UTF8
OPTIONS_RADIO=	TOKYOCABINET
OPTIONS_RADIO_TOKYOCABINET=	TOKYOCABINET_BTREE TOKYOCABINET_MHASH
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--enable-debug
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime
UTF8_CONFIGURE_ON=	--enable-utf8

GEOIP2_DESC=	IP location support
GEOIP2_CONFIGURE_ON=	--enable-geoip=mmdb
GEOIP2_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

SSL_DESC=	Use SSL for WebSocket
SSL_CONFIGURE_ON=	--with-openssl
SSL_USES=	ssl

TOKYOCABINET_DESC=	Tokyo Cabinet support
TOKYOCABINET_BTREE_DESC=	Storage using on-disk B+ Tree
TOKYOCABINET_MHASH_DESC=	Storage using on-memory hash database
TOKYOCABINET_BTREE_CONFIGURE_ON=	--enable-tcb=btree
TOKYOCABINET_MHASH_CONFIGURE_ON=	--enable-tcb=memhash
TOKYOCABINET_BTREE_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet
TOKYOCABINET_MHASH_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

.include <bsd.port.mk>
