# Created by: ijliao
# $FreeBSD$

PORTNAME=	feedparser
PORTVERSION=	5.1.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	An RSS feed parser written in Python

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet

USE_PYTHON=	yes
USE_BZIP2=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	NEWS PKG-INFO README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

regression-test:
	@(cd ${WRKSRC}/${PORTNAME} && ${PYTHON_CMD} ${PORTNAME}test.py)

.include <bsd.port.mk>
