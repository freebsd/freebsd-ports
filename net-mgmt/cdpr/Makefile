# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	cdpr
PORTVERSION=	2.4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Cisco Discovery Protocol Reporter

LICENSE=	GPLv2

USES=		dos2unix tar:tgz
DOS2UNIX_GLOB=	*.c *.h
LDFLAGS+=	-L${LOCALBASE}/lib -lpcap

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} ${PORTNAME}.c cdprs.c conffile.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cdprs/* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cdpr.conf ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.cdprs ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
