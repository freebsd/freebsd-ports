# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	crawl
PORTVERSION=	0.4
PORTREVISION=	11
CATEGORIES=	www
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, efficient web crawler with advanced features

OPTIONS_DEFINE=	EXAMPLES

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

USES=		pkgconfig

USE_BDB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent --program-transform-name=''
CONFIGURE_ENV=	EVENTINC="`pkgconf --cflags libevent`" EVENTLIB="`pkgconf --libs libevent`"

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/include/db2,${BDB_INCLUDE_DIR},g' \
		-e 's,db2,${BDB_LIB_NAME},g' ${WRKSRC}/configure.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/crawl.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
