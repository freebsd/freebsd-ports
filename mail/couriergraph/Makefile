# New ports collection makefile for:	mailgraph
# Date created:			11 September 2005
# Whom:				Xavier Beaudouin (kiwi@oav.net)
#
# $FreeBSD$
#

PORTNAME=	couriergraph
PORTVERSION=	20060202
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.oav.net/couriergraph/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kiwi@oav.net
COMMENT=	A RRDtool frontend for Courier statistics

RUN_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool	\
		p5-File-Tail>=0:${PORTSDIR}/devel/p5-File-Tail

NO_BUILD=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DATADIR?=	/var/db/couriergraph
COURIERGRAPH_USER?=	${WWWOWN}
COURIERGRAPH_GROUP?=	${WWWGRP}

USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	COURIERGRAPH_USER=${COURIERGRAPH_USER} COURIERGRAPH_GROUP=${COURIERGRAPH_GROUP}

STARTUP_FILE=	${PREFIX}/etc/rc.d/couriergraph.sh

SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "DATADIR=/var/db/couriergraph		Where do you put RRD databases?"
	@${ECHO_MSG} "COURIERGRAPH_USER=www			User to run couriergraph (Default: ${WWWOWN})"
	@${ECHO_MSG} "COURIERGRAPH_GROUP=www			Group to run couriergraph (Default: ${WWWGRP})"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/couriergraph.cgi
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/couriergraph.pl

do-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
	${MKDIR} ${DATADIR}
	@${CHOWN} -R ${COURIERGRAPH_USER}:${COURIERGRAPH_GROUP} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/couriergraph.pl ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/couriergraph.cgi ${PREFIX}/www/cgi-bin

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
