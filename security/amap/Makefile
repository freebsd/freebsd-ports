# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	amap
PORTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/groups/thc

MAINTAINER=	onatan@gmail.com
COMMENT=	Application mapper

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

USE_OPENSSL=	yes

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README TODO CHANGES AMAP-LIB-INTERFACE

LOCAL_CONF_FILES=	appdefs.resp appdefs.rpc appdefs.trig

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g; \
		 s|\(-DAMAP_PREFIX\)=\(\$$PREFIX\)|\1=\\\\\\"\2\\\\\\"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|; s|^CC=.*||' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|etc/|etc/amap/|g' ${WRKSRC}/amap-lib.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amap ${STAGEDIR}${PREFIX}/bin
	${LN} -s amap ${STAGEDIR}${PREFIX}/bin/amap6
	${INSTALL_PROGRAM} ${WRKSRC}/amapcrap ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/amap-lib.o ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.for i in amap.h amap-inc.h amap-lib.h
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.endfor
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in ${LOCAL_CONF_FILES}
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
