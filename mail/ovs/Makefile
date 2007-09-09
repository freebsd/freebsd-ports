# New ports collection makefile for:	ovs
# Date created:			26 August 2007
# Whom:				Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	ovs
PORTVERSION=	1.01
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.oav.net/openvisp/stats/

MAINTAINER=	kiwi@oav.net
COMMENT=	A RRDtool frontend for mail statistics

RUN_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/databases/rrdtool	\
		${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail

NO_BUILD=	yes

DATADIR?=	/var/db/ovs
OVS_USER?=	${WWWOWN}
OVS_GROUP?=	${WWWGRP}

USE_RC_SUBR=	${PORTNAME}.sh
SUB_LIST+=	OVS_USER=${OVS_USER} OVS_GROUP=${OVS_GROUP}

DOCS=		README CHANGES COPYING CHANGES.old README.old
.if !defined(NOPORTDOCS)
PORTDOCS=	${DOCS}
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DATADIR=/var/db/ovs		Where do you put RRD databases?"
	@${ECHO_MSG} "OVS_USER=www			User to run mailgraph (Default: ${WWWOWN})"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/ovs.cgi

do-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin
	@${MKDIR} ${PREFIX}/www/data/ovs
	@${MKDIR} ${DATADIR}
	@${CHOWN} -R ${OVS_USER}:${OVS_GROUP} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/ovs.pl ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/ovs.cgi ${PREFIX}/www/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/ovs.css ${PREFIX}/www/data/ovs
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	for f in ${DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

post-install:
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
