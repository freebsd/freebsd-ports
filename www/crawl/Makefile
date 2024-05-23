PORTNAME=	crawl
PORTVERSION=	0.4
PORTREVISION=	17
CATEGORIES=	www
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Small, efficient web crawler with advanced features
WWW=		https://www.monkey.org/~provos/crawl/

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		bdb:18 pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent --program-transform-name=''
CONFIGURE_ENV=	EVENTINC="`pkgconf --cflags libevent`" EVENTLIB="`pkgconf --libs libevent`"

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/include/db2,${BDB_INCLUDE_DIR},g' \
		-e 's,db2,${BDB_LIB_NAME},g' ${WRKSRC}/configure.in

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/crawl.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
