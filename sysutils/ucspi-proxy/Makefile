# Created by: Dale Woolridge <dale.woolridge@gmail.com>
# $FreeBSD$

PORTNAME=	ucspi-proxy
PORTVERSION=	0.98
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/ucspi-proxy/

MAINTAINER=	dale.woolridge@gmail.com
COMMENT=	A proxy program for UCSPI servers and clients

BUILD_DEPENDS=	${BGLIBS_LIB}/libbg-unix.a:${PORTSDIR}/devel/bglibs

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
BGLIBS_INCLUDE=	${LOCALBASE}/include/bglibs

MAN1=		ucspi-proxy-http-xlate.1 ucspi-proxy.1

PLIST_FILES=	bin/ucspi-proxy bin/ucspi-proxy-log bin/ucspi-proxy-pop3 \
		bin/ucspi-proxy-imap bin/ucspi-proxy-http-xlate

NO_STAGE=	yes
do-configure:
	${ECHO_CMD} "${PREFIX}/bin"     > ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"  > ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"   > ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"  > ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INCLUDE}" > ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"     > ${WRKSRC}/conf-bglibs

.include <bsd.port.mk>
