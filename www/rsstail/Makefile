# New ports collection makefile for:	rsstail
# Date created:		21 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rsstail
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	http://www.vanheusden.com/rsstail/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Simple rss monitor

LIB_DEPENDS=	mrss.0:${PORTSDIR}/textproc/libmrss

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|=-O2 -Wall|+=|;/^LDFLAGS/s|=|+=|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
