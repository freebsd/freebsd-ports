# Created by: ijliao
# $FreeBSD$

PORTNAME=	pylize
PORTVERSION=	1.3.b
PORTREVISION=	3
CATEGORIES=	misc textproc
MASTER_SITES=	http://www.chrisarndt.de/en/software/pylize/download/ \
		http://dryice.name/computer/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	dryice@dryice.name
COMMENT=	Presentation generation tool

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_SITELIBDIR}/HTMLgen.py:${PORTSDIR}/www/py-HTMLgen \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/em.py:${PORTSDIR}/textproc/py-empy
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_SITELIBDIR}/HTMLgen.py:${PORTSDIR}/www/py-HTMLgen \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/em.py:${PORTSDIR}/textproc/py-empy

USES=		tar:bzip2
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

do-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} configure.py)

.include <bsd.port.mk>
