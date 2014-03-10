# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	javaview-lite
PORTVERSION=	3.95
PORTREVISION=	2
CATEGORIES=	math java graphics
MASTER_SITES=	http://www.javaview.de/download/data/
DISTFILES=	javaview.zip jv_models.zip jv_tutor.zip
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A 3D viewer and a mathematical visualization software

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USES=		zip
USE_JAVA=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	pkg-message

SCRIPT=		bin/javaview
FIND_DIRS=	\( -type d -not -empty \)
FIND_DATA=	-not -type d
FIND_EXCLUDE=	-not \( -name "*.bat" -or -name "*.bak" -or -name "*.orig" -or -name ".*" -or -name $$(${BASENAME} ${SCRIPT}) -or -name ${SUB_FILES} \)

LINK_OPTS?=	-sf

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		-e 's|%%DATADIR%%|${DATADIR:S/\//\\\//g}|' \
		-e 's|%%JAVA_HOME%%|${JAVA_HOME:S/\//\\\//g}|' \
		${WRKSRC}/${SCRIPT};

do-install:
# Script
	@cd ${WRKSRC}; \
	DIRS=$$(${FIND} . ${FIND_DIRS}); \
	for DIR in $${DIRS}; do \
		${MKDIR} ${DATADIR}/$${DIR}; \
	done; \
	${INSTALL_SCRIPT} ${SCRIPT} ${DATADIR}/${SCRIPT}; \
	${LN} ${LINK_OPTS} ${DATADIR}/${SCRIPT} ${PREFIX}/${SCRIPT};
# Data
	@cd ${WRKSRC}; \
	DATA=$$(${FIND} . ${FIND_DATA} ${FIND_EXCLUDE}) ; \
	for FILE in $${DATA}; do \
		${INSTALL_DATA} $${FILE} ${DATADIR}/$${FILE}; \
	done;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
