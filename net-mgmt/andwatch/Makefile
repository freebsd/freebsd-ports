PORTNAME=	andwatch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	net-mgmt

MAINTAINER=	dennypage@me.com
COMMENT=	ANDwatch - Arp and Neighbor Discovery monitor
WWW=		https://github.com/dennypage/andwatch

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_13=	Does not build

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libcurl.so:ftp/curl

USES=		localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	dennypage

LDFLAGS+=	-L/usr/lib

SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} -e "/LIB_DIR/s,/var/lib,/var/db," \
		${WRKSRC}/andwatch.h
	${REINPLACE_CMD} -e 's/$$(CC)/$$(CC) $$(CFLAGS) $$(LDFLAGS)/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/andwatchd \
		${WRKSRC}/andwatch-query \
		${WRKSRC}/andwatch-query-ma \
		${WRKSRC}/andwatch-update-ma ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/andwatch-notify.sh ${STAGEDIR}${DATADIR}

post-install:
	${MKDIR} ${STAGEDIR}/var/db/andwatch

.include <bsd.port.mk>
