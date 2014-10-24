# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	xmlrpclib
PORTVERSION=	1.0.1
CATEGORIES=	net python
MASTER_SITES=	http://effbot.org/media/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python implementation of the XML-RPC protocol

USES=		python zip

DOCSDIR=	${PREFIX}/share/doc/py-xmlrpclib
EXAMPLESDIR=	${PREFIX}/share/examples/py-xmlrpclib
PORTDOCS=	*
PORTEXAMPLES=	*

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/xmlrpclib.py* \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for egfile in xmlrpcserver.py xmlrpc_handler.py
	${INSTALL_DATA} ${WRKSRC}/${egfile} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
