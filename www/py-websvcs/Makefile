# Ports collection Makefile for:	py-websvcs
# Date created:				August 19 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	websvcs
PORTVERSION=	0.9.7
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SOAPpy${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org

USE_PYTHON=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g} \
		EXAMPLESDIR=${EXAMPLESDIR:S,^${PREFIX}/,,g} \
		DOCSDIR=${DOCSDIR:S,^${PREFIX}/,,g}
TOOLS=		interop2html

do-patch:
.for i in ${TOOLS}
	@${MV} ${WRKSRC}/tools/$i.py ${WRKSRC}/tools/$i
.endfor

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/SOAP.py* ${PYTHON_SITELIBDIR}
.for i in ${TOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/$i ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
