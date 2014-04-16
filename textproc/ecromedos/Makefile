# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	ecromedos
PORTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	textproc print www
MASTER_SITES=	http://www.ecromedos.net/files/${PORTVERSION}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A document preparation system that allows concurrent publication

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt

NO_BUILD=	yes
USE_PYTHON=	yes
USE_TEX=	latex
USE_GNOME=	libxml2 libxslt

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

ECMDS_CONF=	${WRKSRC}/etc/ecmds.conf
ECROMEDOC=	${DATADIR}/doc
ECROMEBIN=	${DATADIR}/bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		     -e 's|%%DATADIR%%|${DATADIR}|g' ${ECMDS_CONF}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "-not ( -name "*.orig" -or -name "*.bak" )"
	${RM} -f ${STAGEDIR}${ECROMEBIN}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${ECROMEBIN}
	${LN} -s ${ECROMEBIN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${LN} -s ${ECROMEBIN} ${STAGEDIR}${PREFIX}/bin/ecmds
	${MV} ${STAGEDIR}${DATADIR}/etc/ecmds.conf ${STAGEDIR}${DATADIR}/etc/ecmds.conf.sample
	${MV} ${STAGEDIR}${DATADIR}/etc/plugins.conf ${STAGEDIR}${DATADIR}/etc/plugins.conf.sample
	${MV} ${STAGEDIR}${ECROMEDOC} ${STAGEDIR}${DOCSDIR}
	${LN} -s ${DOCSDIR} ${STAGEDIR}${ECROMEDOC}

.include <bsd.port.mk>
