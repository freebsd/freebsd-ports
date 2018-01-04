# Created by: kevlo
# $FreeBSD$

PORTNAME=	ntlmaps
PORTVERSION=	0.9.9.0.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Proxy that authenticates the user using the NTLM protocol

USES=		dos2unix python:2.7

DOCS=		COPYING Install.txt changelog.txt readme.txt research.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
	    's,^#! /usr/bin/python,#!${PYTHON_CMD},' ${WRKSRC}/main.py
	@${RM} -r ${WRKSRC}/main.py.bak

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/ntlmaps
	${INSTALL_DATA} ${WRKSRC}/*.py* \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.py* \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${CHMOD} +x ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/main.py
	${LN} -fs ${PYTHON_SITELIBDIR}/${PORTNAME}/main.py \
		${STAGEDIR}${PREFIX}/bin/ntlmaps
	${INSTALL_DATA} ${WRKSRC}/server.cfg \
		${STAGEDIR}${PREFIX}/share/examples/ntlmaps

.include <bsd.port.mk>
