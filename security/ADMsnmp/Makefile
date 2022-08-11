PORTNAME=	ADMsnmp
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	ftp://adm.freelsd.net/pub/ADM/ \
		http://adm.freelsd.net/ADM/ \
		PACKETSTORM/groups/ADM
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	SNMP audit scanner

WRKSRC=		${WRKDIR}/ADMsnmp
USES=		tar:tgz

do-build:
	${CC} ${CFLAGS} -DPORTSHAREDIR="${PREFIX}/share/ADMsnmp" \
		-o ${WRKSRC}/ADMsnmp ${WRKSRC}/snmp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ADMsnmp ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ADMsnmp
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ADMsnmp
	${INSTALL_DATA} ${WRKSRC}/snmp.passwd ${STAGEDIR}${PREFIX}/share/ADMsnmp
	${INSTALL_DATA} ${WRKSRC}/ADMsnmp.README \
		${STAGEDIR}${PREFIX}/share/doc/ADMsnmp

.include <bsd.port.mk>
