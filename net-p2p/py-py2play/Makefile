# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	py2play
PORTVERSION=	0.1.10
PORTREVISION=	1
CATEGORIES=	net-p2p python
MASTER_SITES=	http://download.gna.org/slune/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Py2Play-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Peer-to-peer network game engine

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

DIST_SUBDIR=	python
USES=		python:2.7
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	Py2Play
EXAMPLESDIR=	${PREFIX}/share/examples/py-py2play

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/startdemo ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
