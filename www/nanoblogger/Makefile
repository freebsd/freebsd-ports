# ex:ts=8
# Ports collection makefile for:	nanoblogger
# Date created:			Jul 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nanoblogger
PORTVERSION=	3.4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Small weblog engine written in Bash for the command line

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/nb
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/nb
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR},g" ${WRKSRC}/nb
	@${REINPLACE_CMD} -e "s,%%DOCSDIR%%,${DOCSDIR},g" ${WRKSRC}/nb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/nb.conf ${PREFIX}/etc/nb.conf.sample
	${MKDIR} ${DATADIR}
.for data in default lang lib moods plugins
	${MKDIR} ${DATADIR}/${data} && \
		( cd ${WRKSRC}/${data} && \
			${COPYTREE_SHARE} \* ${DATADIR}/${data} "! -name *.orig" )
.endfor
	${CP} ${WRKSRC}/welcome-to-nb.txt ${DATADIR}

post-install:
	@if [ ! -f ${PREFIX}/etc/nb.conf ]; then \
		${CP} -p ${PREFIX}/etc/nb.conf.sample ${PREFIX}/etc/nb.conf; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in COPYING ChangeLog README TODO copyright
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/nanoblogger.html ${DOCSDIR}/html
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
