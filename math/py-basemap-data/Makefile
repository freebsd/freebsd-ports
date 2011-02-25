# ex:ts=8
# Ports collection makefile for:	py-basemap-data
# Date created:			April 21, 2006
# Whom:				mainland@apeiron.net
#
# $FreeBSD$
#

PORTNAME=	basemap-data
PORTVERSION=	0.9
CATEGORIES=	math python
MASTER_SITES=	SF/matplotlib/matplotlib-toolkits/basemap-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Map data for py-basemap

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

DATADIR=	${PREFIX}/share/py-${PORTNAME}

MAKE_ENV=	BASEMAP_DATA_PATH=${DATADIR}

PLISTDIR=	${DATADIR}/*_[hi].txt \
		${PYTHON_SITELIBDIR}/basemap_data-0.9-py2.5.egg-info

.include <bsd.port.pre.mk>

post-install:
.for dir in ${PLISTDIR}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor
	@${ECHO} "@dirrm ${DATADIR:S,${PREFIX}/,,}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
