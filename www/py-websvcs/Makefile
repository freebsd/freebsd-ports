# Ports collection Makefile for:	py-websvcs
# Date created:				August 19 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	websvcs
PORTVERSION=	0.11.4
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SOAPpy-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Web service libraries includes SOAP, WSDL, UDDI, etc

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst \
		${PYXML}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
TOOLS=		interop2html

do-patch:
.for i in ${TOOLS}
	@${MV} ${WRKSRC}/tools/$i.py ${WRKSRC}/tools/$i
.endfor

post-install:
.for i in ${TOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/$i ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
