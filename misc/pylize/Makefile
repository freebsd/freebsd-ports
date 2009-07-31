# ex:ts=8
# Ports collection makefile for:	pylize
# Date created:			Jun 10, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pylize
PORTVERSION=	1.3.b
PORTREVISION=	2
CATEGORIES=	misc textproc
MASTER_SITES=	http://www.chrisarndt.de/en/software/pylize/download/ \
		http://dryice.name/computer/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	dryice@dryice.name
COMMENT=	A presentation generation tool

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/HTMLgen.py:${PORTSDIR}/www/py-HTMLgen \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/em.py:${PORTSDIR}/textproc/py-empy
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/HTMLgen.py:${PORTSDIR}/www/py-HTMLgen \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/em.py:${PORTSDIR}/textproc/py-empy

USE_BZIP2=	yes
USE_PYTHON=	2.0+
INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGVERSION=	${PORTVERSION:S/.b/b/}

PLIST_FILES=	bin/pylize

post-install:
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
