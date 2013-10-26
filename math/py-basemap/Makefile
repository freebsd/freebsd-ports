# Created by: mainland@apeiron.net
# $FreeBSD$

PORTNAME=	basemap
PORTVERSION=	0.9.2
PORTREVISION=	6
CATEGORIES=	math python
MASTER_SITES=	SF/matplotlib/matplotlib-toolkits/${PORTNAME}-${PORTVERSION}
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
		${DATADIR}
.if !defined(NOPORTDOCS)
PLISTDIR+=	${EXAMPLESDIR}
.endif

NO_STAGE=	yes
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
	@${ECHO} "@unexec rmdir %D/${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/matplotlib/toolkits 2> /dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>
