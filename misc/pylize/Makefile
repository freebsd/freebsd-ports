# Created by: ijliao
# $FreeBSD$

PORTNAME=	pylize
PORTVERSION=	1.3.b
PORTREVISION=	5
CATEGORIES=	misc textproc
MASTER_SITES=	http://www.chrisarndt.de/en/software/pylize/download/ \
		http://dryice.name/computer/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	dryice@dryice.name
COMMENT=	Presentation generation tool

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/HTMLgen.py:www/py-HTMLgen@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR} \
		${PYTHON_SITELIBDIR}/em.py:textproc/py-empy@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7 tar:bzip2
USE_PYTHON=	autoplist distutils

do-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} configure.py)

.include <bsd.port.mk>
