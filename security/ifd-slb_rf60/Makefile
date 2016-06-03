# Created by: Toni Andjelkovic <toni@soth.at>
# $FreeBSD$

PORTNAME=	ifd-slb_rf60
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	http://www.linuxnet.com/drivers/readers/files/
DISTNAME=	${PORTNAME:S/^ifd-//}-drv-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC/SC Lite driver for the Reflex 62 serial smart card reader

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		gmake
CFLAGS+=	-fPIC

SUB_LIST=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME:S/^ifd-//}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README
PLIST_FILES=	lib/pcsc/drivers/libslb_rf60.so

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pcsc/drivers/
	${INSTALL_LIB} ${WRKSRC}/libslb_rf60.so \
		${STAGEDIR}${PREFIX}/lib/pcsc/drivers

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
