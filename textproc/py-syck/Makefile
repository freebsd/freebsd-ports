# Created by: dd
# $FreeBSD$

PORTNAME=	syck
PORTVERSION=	0.61.2
CATEGORIES=	textproc devel python
MASTER_SITES=	http://pyyaml.org/download/pysyck/ \
		LOCAL/avl
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PySyck-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python binding for Syck, a YAML parser and emitter

BUILD_DEPENDS=	${LOCALBASE}/lib/libsyck.a:${PORTSDIR}/textproc/syck

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|#include|include|g ; s|#library_dirs|library_dirs|g ; \
		s|/usr/local|${LOCALBASE}|g ' ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
