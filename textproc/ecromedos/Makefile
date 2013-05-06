# New ports collection makefile for:	ecromedos
# Date created:		2006-04-07
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	ecromedos
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	textproc print www
MASTER_SITES=	http://www.ecromedos.net/files/${PORTVERSION}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A document preparation system that allows concurrent publication

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt

NO_BUILD=	yes
USE_PYTHON=	yes
USE_TEX=	tetex

FIND_DIRS=	-type d
FIND_DATA=	-type f -not \( -name "*.orig" -or -name "*.bak" \)

LN_OPTS=	-sf
RM_OPTS=	-r

ECMDS_CONF=	${WRKSRC}/etc/ecmds.conf
ECROMEDOC=	${DATADIR}/doc
ECROMEBIN=	${DATADIR}/bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		     -e 's|%%DATADIR%%|${DATADIR}|g' ${ECMDS_CONF}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${FIND} . ${FIND_DIRS} -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . ${FIND_DATA} -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${ECROMEBIN}
	${LN} ${LN_OPTS} ${ECROMEBIN} ${PREFIX}/bin/${PORTNAME}
	${LN} ${LN_OPTS} ${ECROMEBIN} ${PREFIX}/bin/ecmds
.if !defined(NOPORTDOCS)
	${MV} ${ECROMEDOC} ${DOCSDIR}
	${LN} ${LN_OPTS} ${DOCSDIR} ${ECROMEDOC}
.else
	${RM} ${RM_OPTS} ${ECROMEDOC}
.endif

.include <bsd.port.mk>
