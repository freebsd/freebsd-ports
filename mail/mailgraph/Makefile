# Created by: Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
# $FreeBSD$

PORTNAME=	mailgraph
PORTVERSION=	1.14
PORTREVISION=	10
CATEGORIES=	mail
MASTER_SITES=	http://mailgraph.schweikert.ch/pub/ \
		http://mailgraph.schweikert.ch/pub/old/

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	RRDtool frontend for Postfix statistics

RUN_DEPENDS=	rrdtool>=0:databases/rrdtool	\
		p5-File-Tail>=0:devel/p5-File-Tail

NO_BUILD=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	mailgraph.pl mailgraph.cgi

CGIDIR?=	${PREFIX}/www/cgi-bin
DATADIR?=	/var/db/mailgraph
WWWROOT?=	${PREFIX}/www/data
MAILGRAPH_USER?=	${WWWOWN}
MAILGRAPH_GROUP?=	${WWWGRP}

USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	MAILGRAPH_USER=${MAILGRAPH_USER} MAILGRAPH_GROUP=${MAILGRAPH_GROUP} PERL=${PERL}
PLIST_SUB=	CGIDIR=${CGIDIR:S,${PREFIX}/,,} WWWROOT=${WWWROOT:S,${PREFIX}/,,}

OPTIONS_DEFINE=	DOCS

DOCS=		README CHANGES
PORTDOCS=	${DOCS}

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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in ${DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${STAGEDIR}${DOCSDIR}; \
	done

.include <bsd.port.mk>
