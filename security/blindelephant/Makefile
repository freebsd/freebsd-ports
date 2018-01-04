# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	blindelephant
PORTVERSION=	1.0
PORTREVISION=	20100819
CATEGORIES=	security www
MASTER_SITES=	LOCAL/niels \
		http://people.freebsd.org/~niels/distfiles/
DISTNAME=	${PORTNAME}-${PORTREVISION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fingerprint the web applications used by a web site

LICENSE=	LGPL3

USES=		python:2.7 tar:bzip2
USE_PYTHON=	distutils
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PATH=${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

PORTDOCS=	README Blind_Elephant_BlackHat_2010.pdf

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/src/* ${WRKSRC}
	@${MV} "${WRKSRC}/doc/Blind Elephant - BlackHat 2010.pdf" \
	${WRKSRC}/Blind_Elephant_BlackHat_2010.pdf

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
