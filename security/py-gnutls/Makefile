# New ports collection makefile for:	py-gnutls
# Date created:		Apr. 06, 2007
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	1.1.9
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-gnutls-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python wrapper for the GNUTLS library

LIB_DEPENDS=	gnutls.40:${PORTSDIR}/security/gnutls
RUN_DEPENDS=	${PYCTYPES}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_gnutls

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e "s|include_dirs=\[\]|include_dirs=\['${LOCALBASE}/include'\]|" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s|library_dirs=\[\]|library_dirs=\['${LOCALBASE}/lib'\]|" ${WRKSRC}/setup.py

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
