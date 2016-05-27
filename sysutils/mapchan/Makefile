# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD$

PORTNAME=	mapchan
PORTVERSION=	3.2
CATEGORIES=	sysutils converters
MASTER_SITES=	SF

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Transform the input and output of a terminal (SCO Unix alike)

USES=		iconv tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	STAGEDIR=${STAGEDIR} MAPDIR=${STAGEDIR}${PREFIX}/etc/${PORTNAME}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${WRKSRC}/doc/mapchan.F ${WRKSRC}/doc/mapchan.8

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/mapchan.8 ${STAGEDIR}${MANPREFIX}/man/man8

post-patch:
	@${MV} ${WRKSRC}/examples/default ${WRKSRC}/examples/default.sample
	@${RM} ${WRKSRC}/examples/default.orig
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" ${WRKSRC}/mapchan.c
	${REINPLACE_CMD} -e "s|utmp.h|utmpx.h|" ${WRKSRC}/mapchan.c

.include <bsd.port.mk>
