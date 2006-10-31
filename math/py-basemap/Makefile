# ex:ts=8
# Ports collection makefile for:	py-basemap
# Date created:			April 21, 2006
# Whom:				mainland@apeiron.net
#
# $FreeBSD$
#

PORTNAME=	basemap
PORTVERSION=	0.9.2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	matplotlib
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Plots data on map projections (with continental and political boundaries)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/matplotlib/:${PORTSDIR}/math/py-matplotlib

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

DATADIR=	${PREFIX}/share/py-${PORTNAME}-data
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

MAKE_ENV=	BASEMAP_DATA_PATH=${DATADIR}

PLISTDIR=	${PYTHON_SITELIBDIR}/matplotlib/toolkits/basemap \
		${PYTHON_SITELIBDIR}/shapelib \
		${PYTHON_SITELIBDIR}/dbflib \
		${PYTHON_SITELIBDIR}/dbflibc.so \
		${PYTHON_SITELIBDIR}/shptree.so \
		${PYTHON_SITELIBDIR}/shapelibc.so \
		${PYTHON_SITELIBDIR}/pyproj.so \
		${PYTHON_SITELIBDIR}/basemap-0.9.2-py2.5.egg-info \
		${DATADIR}
.if !defined(NOPORTDOCS)
PLISTDIR+=	${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>
post-patch:
	@${GREP} -lR "share/basemap" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s,share/basemap,share/py-basemap-data,g"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif
.for dir in ${PLISTDIR}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
