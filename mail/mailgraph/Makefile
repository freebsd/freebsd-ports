# Created by: Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
# $FreeBSD$

PORTNAME=	mailgraph
PORTVERSION=	1.14
PORTREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	http://mailgraph.schweikert.ch/pub/ \
		http://mailgraph.schweikert.ch/pub/old/

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A RRDtool frontend for Postfix statistics

RUN_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool	\
		p5-File-Tail>=0:${PORTSDIR}/devel/p5-File-Tail

NO_BUILD=	yes
USES=		perl5

CGIDIR?=	${PREFIX}/www/cgi-bin
DATADIR?=	/var/db/mailgraph
WWWROOT?=	${PREFIX}/www/data
MAILGRAPH_USER?=	${WWWOWN}
MAILGRAPH_GROUP?=	${WWWGRP}

USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	MAILGRAPH_USER=${MAILGRAPH_USER} MAILGRAPH_GROUP=${MAILGRAPH_GROUP}
PLIST_SUB=	CGIDIR=${CGIDIR:S,${PREFIX}/,,} WWWROOT=${WWWROOT:S,${PREFIX}/,,}

DOCS=		README CHANGES
.if !defined(NOPORTDOCS)
PORTDOCS=	${DOCS}
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DATADIR=/var/db/mailgraph	Where do you put RRD databases?"
	@${ECHO_MSG} "CGIDIR=${PREFIX}/www/cgi-bin	Where do you put cgi?"
	@${ECHO_MSG} "WWWROOT=${PREFIX}/www/data	Where do you put httpd's document root?"
	@${ECHO_MSG} "MAILGRAPH_USER=www		User to run mailgraph (Default: ${WWWOWN})"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/mailgraph.cgi

do-install:
	${MKDIR} ${STAGEDIR}${CGIDIR}
	${MKDIR} ${STAGEDIR}${WWWROOT}/mailgraph
	@${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.pl ${STAGEDIR}${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.cgi ${STAGEDIR}${CGIDIR}
	@${INSTALL_DATA} ${WRKSRC}/mailgraph.css ${STAGEDIR}${WWWROOT}/mailgraph
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in ${DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${STAGEDIR}${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
