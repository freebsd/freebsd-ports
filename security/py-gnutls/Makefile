# New ports collection makefile for:	py-gnutls
# Date created:		Apr. 06, 2007
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	1.0.0
CATEGORIES=	security python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/p/python-gnutls/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-gnutls-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python wrapper for the GNUTLS library

LIB_DEPENDS=	gnutls.15:${PORTSDIR}/security/gnutls

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${TARGETDIR}/share/examples/py-${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e "s|include_dirs=\[\]|include_dirs=\['${LOCALBASE}/include'\]|" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s|library_dirs=\[\]|library_dirs=\['${LOCALBASE}/lib'\]|" ${WRKSRC}/setup.py
	${FIND} ${WRKSRC}/gnutls/library -type f | ${XARGS} ${REINPLACE_CMD} -e 's/libgnutls.so.13/libgnutls.so.15/g'
	${FIND} ${WRKSRC}/gnutls/library -type f | ${XARGS} ${REINPLACE_CMD} -e 's/libgnutls-extra.so.13/libgnutls-extra.so.15/g'

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ctypes/__init__.py:${PORTSDIR}/devel/py-ctypes
.endif

.include <bsd.port.post.mk>
