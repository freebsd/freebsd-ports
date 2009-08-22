# New ports collection makefile for:	py-spf
# Date created:				26 Dec 2004
# Whom:					Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spf
PORTVERSION=	2.0.5
CATEGORIES=	mail python
MASTER_SITES=	SF/pymilter/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Python implementation of the RFC 4408 SPF protocol

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/DNS/__init__.py:${PORTSDIR}/dns/py-dns

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyspf

PORTDOCS=	CHANGELOG README

DOCSDIR?=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${CHMOD} 755 ${PYTHONPREFIX_SITELIBDIR}/spf.py
	@${LN} -s ${PYTHONPREFIX_SITELIBDIR}/spf.py ${PREFIX}/bin

.include <bsd.port.mk>
