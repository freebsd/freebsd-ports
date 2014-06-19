# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	plman
PORTVERSION=	2.5.1
PORTREVISION=	2
CATEGORIES=	math java
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/dist/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}.sourceforge.net/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\./_/g}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A Propositional Logic sentence shell/interpreter

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

NO_BUILD=	yes

USES=		zip
USE_JAVA=	yes

JAVA_VERSION=	1.6+
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
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}/${FIND_DATA}
	cd ${WRKSRC} && ${FIND} ${FIND_DATA} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/${FIND_DOCS} && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
.endif

.include <bsd.port.mk>
