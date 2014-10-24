# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-gnutls-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python wrapper for the GNUTLS library

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	python_gnutls

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e "s|include_dirs=.*|include_dirs=\['${LOCALBASE}/include'\],|" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s|library_dirs=.*|library_dirs=\['${LOCALBASE}/lib'\],|" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s|\.26||g" ${WRKSRC}/gnutls/library/functions.py

post-install:
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
