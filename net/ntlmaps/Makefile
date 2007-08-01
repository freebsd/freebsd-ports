# New ports collection makefile for:	ntlmaps
# Date created:				1 August 2007
# Whom:					kevlo
#
# $FreeBSD$

PORTNAME=	ntlmaps
PORTVERSION=	0.9.9.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A proxy software that authenticates using the NTLM protocol

USE_PYTHON=	yes
NO_BUILD=	yes

DOCS=		COPYING Install.txt changelog.txt readme.txt research.txt

post-patch:
	${REINPLACE_CMD} -e \
	    's,^#! /usr/bin/python,#!${PYTHON_CMD},' ${WRKSRC}/main.py
do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/examples/ntlmaps
	${INSTALL_DATA} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.py ${PYTHON_SITELIBDIR}/${PORTNAME}
	${CHMOD} +x ${PYTHON_SITELIBDIR}/${PORTNAME}/main.py
	${LN} -fs ${PYTHON_SITELIBDIR}/${PORTNAME}/main.py ${PREFIX}/bin/ntlmaps
	${INSTALL_DATA} ${WRKSRC}/server.cfg ${PREFIX}/share/examples/ntlmaps

.include <bsd.port.mk>
