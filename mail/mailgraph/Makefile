# New ports collection makefile for:	mailgraph
# Date created:			30 August 2002
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	mailgraph
PORTVERSION=	1.11
CATEGORIES=	mail
MASTER_SITES=	http://people.ee.ethz.ch/~dws/software/mailgraph/pub/ \
		http://people.ee.ethz.ch/~dws/software/mailgraph/pub/old/

MAINTAINER=	rafan@infor.org
COMMENT=	A RRDtool frontend for Postfix statistics

RUN_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/net/rrdtool	\
		${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail

NO_BUILD=	yes

DATADIR?=	/var/db/mailgraph
MAILGRAPH_USER?=	${WWWOWN}
MAILGRAPH_GROUP?=	${WWWGRP}

USE_REINPLACE=	yes
USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} DATADIR=${DATADIR} \
		MAILGRAPH_USER=${MAILGRAPH_USER} MAILGRAPH_GROUP=${MAILGRAPH_GROUP}
STARTUP_FILE=	${PREFIX}/etc/rc.d/mailgraph.sh

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "DATADIR=/var/db/mailgraph		Where do you put RRD databases?"
	@${ECHO_MSG} "MAILGRAPH_USER=www			User to run mailgraph (Default: ${WWWOWN})"
	@${ECHO_MSG} "MAILGRAPH_GROUP=www			Group to run mailgraph (Default: ${WWWGRP})"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/mailgraph.cgi
	@${SED} 's|%%DATADIR%%|${DATADIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

do-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
	${MKDIR} ${DATADIR}
	@${CHOWN} -R ${MAILGRAPH_USER}:${MAILGRAPH_GROUP} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.pl ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.cgi ${PREFIX}/www/cgi-bin
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/mailgraph.sh.tmpl > ${STARTUP_FILE}
	@${CHMOD} 755 ${STARTUP_FILE}

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
