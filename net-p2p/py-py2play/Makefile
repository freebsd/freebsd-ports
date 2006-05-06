# New ports collection makefile for:	py-py2play
# Date created:				2005-10-05
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	py2play
PORTVERSION=	0.1.9
CATEGORIES=	net-p2p python
MASTER_SITES=	http://download.gna.org/slune/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Py2Play-${PORTVERSION}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Peer-to-peer network game engine

DIST_SUBDIR=	python
USE_GZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/py-py2play

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/startdemo ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
