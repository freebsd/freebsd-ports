# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD$

PORTNAME=	mapchan
PORTVERSION=	3.2
CATEGORIES=	sysutils converters
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Transform the input and output of a terminal (SCO Unix alike)

USES=		iconv
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	MAPDIR=${PREFIX}/etc/${PORTNAME}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
ETCDAT=		*.map default.sample
MAN8=		mapchan.8
PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
post-extract:
	@${CP} ${WRKSRC}/doc/mapchan.F ${WRKSRC}/doc/mapchan.8

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/mapchan.8 ${MANPREFIX}/man/man8
.endif

.include <bsd.port.pre.mk>

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${CP} ${WRKSRC}/examples/default ${WRKSRC}/examples/default.sample
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" ${WRKSRC}/mapchan.c
.if ${OSVERSION} > 900007
	${REINPLACE_CMD} -e "s|utmp.h|utmpx.h|" ${WRKSRC}/mapchan.c
.endif

.include <bsd.port.post.mk>
