# New ports collection makefile for:	plman
# Date created:		2005-12-12
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	plman
PORTVERSION=	2.5.1
CATEGORIES=	math java
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/dist/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}.sourceforge.net/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\./_/g}
EXTRACT_SUFX=	.zip

MAINTAINER=	nivit@email.it
COMMENT=	A Propositional Logic sentence shell/interpreter

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

NO_BUILD=	yes

USE_JAVA=	yes
USE_ZIP=	yes

JAVA_VERSION=	1.4+
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
REPLACE_FILES=	${WRKSRC}/bin/${PORTNAME}
WRKSRC=	${WRKDIR}/${PORTNAME}

FIND_DATA=	lib
FIND_DOCS=	docs

post-patch:
	for FILE in ${REPLACE_FILES}; do \
	    ${REINPLACE_CMD} -e "/%%DATADIR%%/s//${DATADIR:S/\//\\\//g}/g" $${FILE} ;\
	done;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}/${FIND_DATA}
	cd ${WRKSRC} && ${FIND} ${FIND_DATA} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/${FIND_DOCS} && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.mk>
