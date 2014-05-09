# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	py2play
PORTVERSION=	0.1.10
CATEGORIES=	net-p2p python
MASTER_SITES=	http://download.gna.org/slune/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Py2Play-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Peer-to-peer network game engine

LICENSE=	GPLv2

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Py2Play
EXAMPLESDIR=	${PREFIX}/share/examples/py-py2play

post-install:
.ifndef NOPORTEXAMPLES
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/startdemo ${STAGEDIR}${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
