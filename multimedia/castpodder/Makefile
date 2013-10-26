# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	castpodder
PORTVERSION=	5.1
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://nivi.interfree.it/distfiles/${PORTNAME}/
DISTNAME=	CastPodder-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A podcast receiver written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xmms/__init__.py:${PORTSDIR}/audio/py-xmms \
		${PYTHON_SITELIBDIR}/bmp/__init__.py:${PORTSDIR}/multimedia/py-pybmp \
		${PYTHON_SITELIBDIR}/${WX_PYTHON_DIR}/wxPython/_wx.py:${PORTSDIR}/x11-toolkits/py-wxPython26-unicode \
		${PYTHON_PKGNAMEPREFIX}bsddb>0:${PORTSDIR}/databases/py-bsddb
.if !defined(WITH_BMP)
RUN_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
.else
RUN_DEPENDS+=	bmpx:${PORTSDIR}/multimedia/bmpx
.endif

NO_BUILD=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}
WX_PYTHON_DIR=	wx-2.6-gtk2-unicode

FIND_DIRS=	-type d
FIND_DATA=	-type f -not -name "${CASTPOD_SCRIPT}"

CASTPOD_SCRIPT=	CastPodder.sh
PORTNAME2=	CastPodder
PORTNAME3=	iPodder
RM_FILES=	AUTHORS COPY CREDITS INSTALL KNOWN-ISSUES LICENSE NOTES README THANKS TODO gpl.txt install.sh make-distribution.sh

LN_OPTS=	-sf
RM_OPTS=	-rf

NO_STAGE=	yes
post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' -e "s|ensureMinimal('2.6')|select('${WX_PYTHON_DIR:S/^wx-//g}')|g" CastPodderGui.py ${CASTPOD_SCRIPT}
	cd ${WRKSRC} && ${RM} ${RM_OPTS} *.bak *.orig

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${CASTPOD_SCRIPT} ${DATADIR}/${CASTPOST_SCRIPT}
	cd ${WRKSRC} && ${FIND} . ${FIND_DIRS} -exec ${MKDIR} ${DATADIR}/{} ";"
	cd ${WRKSRC} && ${FIND} . ${FIND_DATA} -exec ${INSTALL_DATA} {} ${DATADIR}/{} ";"
	cd ${DATADIR} && ${FIND} ${RM_FILES} -delete
.if !defined(NOPORTDOCS)
	${MV} ${DATADIR}/docs ${DOCSDIR}
.else
	${RM} ${RM_OPTS} ${DATADIR}/docs
.endif
	${LN} ${LN_OPTS} ${DATADIR}/${CASTPOD_SCRIPT} ${PREFIX}/bin/${PORTNAME}
	${LN} ${LN_OPTS} ${DATADIR}/${CASTPOD_SCRIPT} ${PREFIX}/bin/${PORTNAME2}
	${LN} ${LN_OPTS} ${DATADIR}/${CASTPOD_SCRIPT} ${PREFIX}/bin/${PORTNAME3}

.include <bsd.port.mk>
