# New ports collection makefile for:	py-google
# Date created:		22 April 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	google
PORTVERSION=	0.5.2
CATEGORIES=	net python
MASTER_SITES=	http://diveintomark.org/projects/pygoogle/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygoogle-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_xmlplus/sax/__init__.py:${PORTSDIR}/textproc/py-xml

USE_PYTHON=	yes
USE_ZIP=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
EXTRACT_BEFORE_ARGS=	-q -aa

WRKSRC=		${WRKDIR}/pygoogle
EXAMPLESDIR=	${PREFIX}/share/examples/py-google

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
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
