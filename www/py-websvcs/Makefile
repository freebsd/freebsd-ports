# Ports collection Makefile for:	py-websvcs
# Date created:				August 19 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	websvcs
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SOAPpy${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Web service libraries includes SOAP, WSDL, UDDI, etc

USE_PYTHON=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=	EXAMPLESDIR=${EXAMPLESDIR:S,^${PREFIX}/,,g} \
		DOCSDIR=${DOCSDIR:S,^${PREFIX}/,,g}
NO_BUILD=	yes
TOOLS=		interop2html
PY_FILES=	SOAP

do-patch:
.for i in ${TOOLS}
	@${MV} ${WRKSRC}/tools/$i.py ${WRKSRC}/tools/$i
.endfor

do-install:
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
.for f in ${PY_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f}.py ${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -c "import py_compile; py_compile.compile('${PYTHON_SITELIBDIR}/${f}.py')"
	@${PYTHON_CMD} -O -c "import py_compile; py_compile.compile('${PYTHON_SITELIBDIR}/${f}.py')"
.endfor
.for i in ${TOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/$i ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
