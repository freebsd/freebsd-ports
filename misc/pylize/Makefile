# ex:ts=8
# Ports collection makefile for:	pylize
# Date created:			Jun 10, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pylize
PORTVERSION=	1.1b
CATEGORIES=	misc
MASTER_SITES=	http://www.chrisarndt.de/en/software/pylize/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A presentation generation tool

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/HTMLgen.py:${PORTSDIR}/www/py-HTMLgen \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/HTMLgen.py:${PORTSDIR}/www/py-HTMLgen \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging

USE_BZIP2=	yes
USE_PYTHON=	yes

PLIST_FILES=	bin/pylize

post-install:
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
