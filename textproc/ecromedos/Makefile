# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	ecromedos
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	textproc print www
MASTER_SITES=	http://www.ecromedos.net/files/src/${PORTVERSION}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Document preparation system that allows concurrent publication

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libxml2>=0:textproc/py-libxml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libxslt>=0:textproc/py-libxslt@${PY_FLAVOR} \
		convert:graphics/ImageMagick \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}

NO_BUILD=	yes

USES=		python:2.7
USE_GNOME=	libxml2 libxslt
USE_TEX=	latex

post-patch:
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} \
		-e 's|^\#!${SETENV} python|\#!${PYTHON_CMD}|1' \
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
