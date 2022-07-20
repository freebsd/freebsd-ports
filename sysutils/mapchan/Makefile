PORTNAME=	mapchan
PORTVERSION=	3.2
PORTREVISION=	3
CATEGORIES=	sysutils converters
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Transform the input and output of a terminal (SCO Unix alike)

LICENSE=	GPLv2

USES=		iconv tar:tgz

MAKE_ENV=	MAPDIR=${STAGEDIR}${PREFIX}/etc/${PORTNAME} \
		STAGEDIR=${STAGEDIR}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${WRKSRC}/doc/mapchan.F ${WRKSRC}/doc/mapchan.8

post-patch:
	@${MV} ${WRKSRC}/examples/default ${WRKSRC}/examples/default.sample
	@${RM} ${WRKSRC}/examples/default.orig
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" ${WRKSRC}/mapchan.c
	${REINPLACE_CMD} -e "s|utmp.h|utmpx.h|" ${WRKSRC}/mapchan.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/mapchan.8 ${STAGEDIR}${MANPREFIX}/man/man8

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
