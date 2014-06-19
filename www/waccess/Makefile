# Created by: tundra
# $FreeBSD$

PORTNAME=	waccess
PORTVERSION=	2.0
CATEGORIES=	www textproc
MASTER_SITES=	http://www.tundraware.com/Software/waccess/

MAINTAINER=	tundra@tundraware.com
COMMENT=	Quick-N-Dirty Web Access Log Analyzer

USE_PYTHON=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/waccess ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/waccess.1.gz ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/waccess-license.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
