# New ports collection makefile for:	py-spf
# Date created:				26 Dec 2004
# Whom:					Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spf
PORTVERSION=	1.6
CATEGORIES=	mail python
MASTER_SITES=	http://www.wayforward.net/spf/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Python implementation of SPF

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/DNS/__init__.py:${PORTSDIR}/dns/py-dns

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pyspf

DOCSDIR?=	${PREFIX}/share/doc/py-${PORTNAME}

PLIST_FILES=	bin/spf.py \
		%%PYTHON_SITELIBDIR%%/spf.py \
		%%PYTHON_SITELIBDIR%%/spf.pyc \
		%%PYTHON_SITELIBDIR%%/spf.pyo

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CHMOD} 755 ${PYTHONPREFIX_SITELIBDIR}/spf.py
	@${LN} -s ${PYTHONPREFIX_SITELIBDIR}/spf.py ${PREFIX}/bin

.include <bsd.port.mk>
