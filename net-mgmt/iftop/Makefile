# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	iftop
PORTVERSION=	0.17
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Display bandwidth usage on an interface by host

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-resolver=netdb_1thread

PORTDOCS=	README
PLIST_FILES=	bin/iftop man/man8/iftop.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		 ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
