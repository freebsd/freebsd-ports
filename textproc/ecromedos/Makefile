# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	ecromedos
PORTVERSION=	2.1.0
PORTREVISION=	0
CATEGORIES=	textproc print www
MASTER_SITES=	http://www.ecromedos.net/files/src/${PORTVERSION}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Document preparation system that allows concurrent publication

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:textproc/py-libxslt \
		convert:graphics/ImageMagick \
		pygmentize:textproc/py-pygments

NO_BUILD=	yes

USES=		python:2
USE_GNOME=	libxml2 libxslt
USE_TEX=	latex

post-patch:
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} \
		-e 's|^\#!${SETENV} python|&2|1' \
		-e 's|[^!]/usr/bin|${LOCALBASE}/bin|g' \
		-e 's|%%ETCDIR%%|${ETCDIR}|g' \
		bin/${PORTNAME} etc/ecmds.conf lib/ecmds/configreader.py)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC} ; \
	${COPYTREE_SHARE} "data lib transform" ${STAGEDIR}${DATADIR} \
		"-not ( -name "*.orig" -or -name "*.bak" )" ; \
	${INSTALL_DATA} etc/ecmds.conf ${STAGEDIR}${ETCDIR}/ecmds.conf.sample ; \
	${INSTALL_DATA} etc/plugins.conf ${STAGEDIR}${ETCDIR}/plugins.conf.sample ; \
	${INSTALL_SCRIPT} bin/${PORTNAME} ${STAGEDIR}${DATADIR}/bin/${PORTNAME})
	@(cd ${STAGEDIR}${PREFIX}/bin ; \
	${LN} -s ../${DATADIR_REL}/bin/${PORTNAME}  ecmds ; \
	${LN} -s ../${DATADIR_REL}/bin/${PORTNAME} ${PORTNAME})

.include <bsd.port.mk>
