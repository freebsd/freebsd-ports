# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pypanda
PORTVERSION=	0.6
PORTREVISION=	9
CATEGORIES=	misc
MASTER_SITES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for San Diego Zoo Pandacam written in Python

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

RUN_DEPENDS=	${PYGAME}

USES=		python

OPTIONS_DEFINE=	DOCS

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.py *.pyc *.pyo *.jpg *.png \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@printf "#!/bin/sh\ncd ${DATADIR} && \
		exec ${PYTHON_CMD} ${DATADIR}/pypanda.py\n" > ${WRKDIR}/pypanda.sh
	${INSTALL_SCRIPT} ${WRKDIR}/pypanda.sh ${STAGEDIR}${PREFIX}/bin/pypanda

.include <bsd.port.mk>
