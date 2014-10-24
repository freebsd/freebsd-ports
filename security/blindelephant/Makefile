# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	blindelephant
PORTVERSION=	1.0
PORTREVISION=	20100819
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~niels/distfiles/
MASTER_SITE_SUBDIR=	niels
DISTNAME=	${PORTNAME}-${PORTREVISION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fingerprint the web applications used by a web site

LICENSE=	LGPL3

USES=		python tar:bzip2
USE_PYTHON=	distutils

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PATH=${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README Blind_Elephant_BlackHat_2010.pdf

post-extract:
	@${MV} ${WRKSRC}/src/* ${WRKSRC}
	@${MV} "${WRKSRC}/doc/Blind Elephant - BlackHat 2010.pdf" \
	${WRKSRC}/Blind_Elephant_BlackHat_2010.pdf

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.	for I in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${I} ${STAGEDIR}${DOCSDIR}
.	endfor

.include <bsd.port.mk>
