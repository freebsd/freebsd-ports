# Created by: dd
# $FreeBSD$

PORTNAME=	syck
PORTVERSION=	0.61.2
PORTREVISION=	1
CATEGORIES=	textproc devel python
MASTER_SITES=	http://pyyaml.org/download/pysyck/ \
		LOCAL/avl
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PySyck-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python binding for Syck, a YAML parser and emitter

BUILD_DEPENDS=	${LOCALBASE}/lib/libsyck.a:textproc/syck

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|#include|include|g ; s|#library_dirs|library_dirs|g ; \
		s|/usr/local|${LOCALBASE}|g ' ${WRKSRC}/setup.cfg

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_syck.so

.include <bsd.port.mk>
