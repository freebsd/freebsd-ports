# New ports collection makefile for:	py-xmlrpclib
# Date created:		29 May 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	xmlrpclib
PORTVERSION=	0.9.9
CATEGORIES=	net python
MASTER_SITES=	http://www.pythonware.com/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xmlrpc-${PORTVERSION}-010226

MAINTAINER=	wjv@FreeBSD.org

USE_PYTHON=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

XRL_DOCDIR=	${PREFIX}/share/doc/py-xmlrpclib
XRL_EGDIR=	${PREFIX}/share/examples/py-xmlrpclib

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/xmlrpclib.py* \
	  ${PREFIX}/lib/${PYTHON_VERSION}/site-packages
	@ ${MKDIR} ${XRL_EGDIR}
.for egfile in xmlrpcserver.py xmlrpc_handler.py
	@ ${INSTALL_DATA} ${WRKSRC}/${egfile} ${XRL_EGDIR}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${XRL_DOCDIR}
	@ ${INSTALL_MAN} ${WRKSRC}/README ${XRL_DOCDIR}
.endif

.include <bsd.port.mk>
