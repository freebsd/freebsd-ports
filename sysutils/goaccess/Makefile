# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	goaccess
PORTVERSION=	1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://tar.goaccess.io/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Real-time Apache web log analyzer

LICENSE=	MIT

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USES=		pkgconfig

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

CONFIGURE_ARGS=	--enable-utf8

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS GEOIP TOKYOCABINET
OPTIONS_DEFAULT=	GEOIP

GEOIP_CONFIGURE_ON=	--enable-geoip
GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP

TOKYOCABINET_DESC=	Tokyo Cabinet support
TOKYOCABINET_CONFIGURE_ON=	--enable-tcb=btree
TOKYOCABINET_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
