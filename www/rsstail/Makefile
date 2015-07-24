# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsstail
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://www.vanheusden.com/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple RSS monitor

LICENSE=	GPLv2

LIB_DEPENDS=	libmrss.so:${PORTSDIR}/textproc/libmrss

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		iconv tar:tgz

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/ s|=|+=|; /^LDFLAGS/ s|=|+=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
