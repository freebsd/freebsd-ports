# Created by: Colin Percival
# $FreeBSD$

PORTNAME=	pkesh
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.daemonology.net/pkesh/

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Public Key Encryption SHell script

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes

PLIST_FILES=	bin/pkesh
PORTDOCS=	README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkesh.sh ${STAGEDIR}${PREFIX}/bin/pkesh
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
