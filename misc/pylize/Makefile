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
COMMENT=	A presentation generation tool

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_SITELIBDIR}/HTMLgen.py:${PORTSDIR}/www/py-HTMLgen \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/em.py:${PORTSDIR}/textproc/py-empy
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_SITELIBDIR}/HTMLgen.py:${PORTSDIR}/www/py-HTMLgen \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/em.py:${PORTSDIR}/textproc/py-empy

USE_BZIP2=	yes
USE_PYTHON=	2
INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGVERSION=	${PORTVERSION:S/.b/b/}

PLIST_FILES=	bin/pylize

NO_STAGE=	yes
post-install:
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
