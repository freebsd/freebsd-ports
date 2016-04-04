# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	hexinject
PORTVERSION=	1.5
CATEGORIES=	net security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	HexInject is a very versatile packet injector and sniffer

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcap.so:net/libpcap

PLIST_FILES=	bin/${PORTNAME}

WRKSRC=	${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's#gcc#${CC}#g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '2s#-lpcap#-L${LOCALBASE}/lib -lpcap#' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
