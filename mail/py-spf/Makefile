# New ports collection makefile for:	py-spf
# Date created:				26 Dec 2004
# Whom:					Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spf
PORTVERSION=	2.0.4
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pymilter
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Python implementation of the RFC 4408 SPF protocol

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/DNS/__init__.py:${PORTSDIR}/dns/py-dns

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyspf

DOCSDIR?=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
.endif
	@${CHMOD} 755 ${PYTHONPREFIX_SITELIBDIR}/spf.py
	@${LN} -s ${PYTHONPREFIX_SITELIBDIR}/spf.py ${PREFIX}/bin

.include <bsd.port.mk>
