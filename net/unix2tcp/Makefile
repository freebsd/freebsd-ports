PORTNAME=	unix2tcp
PORTVERSION=	0.8.3
CATEGORIES=	net
MASTER_SITES=	https://codeberg.org/portmaster/${PORTNAME}/archive/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
DISTNAME=	${PORTNAME}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Connection forwarder that converts Unix sockets into TCP sockets
WWW=		https://codeberg.org/portmaster/unix2tcp/

LICENSE=	GPLv2

CFLAGS+=	-DHAVE_CONFIG_H -I.
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -c ${PORTNAME}.c -o ${PORTNAME}.o &&\
	${CC} ${CFLAGS} -c server.c -o server.o &&\
	${CC} ${CFLAGS} -c mylog.c -o mylog.o &&\
	${CC} ${CFLAGS} -c list.c -o list.o &&\
	${CC} ${PORTNAME}.o server.o mylog.o list.o -o ${PORTNAME} && \
	${CC} ${CFLAGS} -c utelnet.c -o utelnet.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
