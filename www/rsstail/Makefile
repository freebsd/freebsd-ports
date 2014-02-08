# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsstail
PORTVERSION=	1.8
CATEGORIES=	www
MASTER_SITES=	http://www.vanheusden.com/rsstail/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Simple RSS monitor

LIB_DEPENDS=	mrss.19:${PORTSDIR}/textproc/libmrss

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/rsstail.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|=-O2 -Wall|+=|;/^LDFLAGS/s|=|+=|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
