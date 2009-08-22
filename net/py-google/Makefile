# New ports collection makefile for:	py-google
# Date created:		22 April 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	google
PORTVERSION=	0.6
CATEGORIES=	net python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygoogle-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python wrapper for the Google web API

RUN_DEPENDS=	${PYXML}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pygoogle
PYDISTUTILS_PKGVERSION=	0.5

.if !defined(NOPORTDOCS)
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/py-google
EXAMPLESDIR=	${PREFIX}/share/examples/py-google
.endif

post-patch:
# www/py-websvcs has an incompatible version of SOAP.py
	@${MV} ${WRKSRC}/SOAP.py ${WRKSRC}/SOAPgoogle.py
	@cd ${WRKSRC}; for f in *.py; do \
		${REINPLACE_CMD} -e 's,import SOAP,import SOAPgoogle as SOAP,g' $$f; \
	done
	@${MKDIR} ${WRKSRC}/tests
	@${MV} ${WRKSRC}/*test*.py ${WRKSRC}/tests
	@${REINPLACE_CMD} -e 's,.*extra_path.*,,g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/tests/*.py ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
