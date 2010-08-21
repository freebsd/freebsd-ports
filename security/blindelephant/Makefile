# New ports collection makefile for:    blindelephant
# Date created:				2010-08-19
# Whom:					Niels Heinen
#
# $FreeBSD$
#

PORTNAME=	blindelephant
PORTVERSION=	1.0
PORTREVISION=	20100819
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~niels/distfiles/
MASTER_SITE_SUBDIR=	niels
DISTNAME=	${PORTNAME}-${PORTREVISION}

MAINTAINER=	niels@FreeBSD.org
COMMENT=	Fingerprint the web applications used by a web site

LICENSE=	LGPL3
USE_BZIP2=	YES
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	YES

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PATH=${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

PORTDOCS=	README Blind_Elephant_BlackHat_2010.pdf

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKSRC}/src/* ${WRKSRC}
	@${MV} "${WRKSRC}/doc/Blind Elephant - BlackHat 2010.pdf" \
	${WRKSRC}/Blind_Elephant_BlackHat_2010.pdf

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for I in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${I} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.post.mk>
