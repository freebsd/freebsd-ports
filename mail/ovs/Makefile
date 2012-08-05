# New ports collection makefile for:	ovs
# Date created:			26 August 2007
# Whom:				Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	ovs
PORTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.oav.net/openvisp/stats/

MAINTAINER=	kiwi@oav.net
COMMENT=	A RRDtool frontend for mail statistics

RUN_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool	\
		p5-File-Tail>=0:${PORTSDIR}/devel/p5-File-Tail

NO_BUILD=	yes
USE_PERL5=	yes

CGIDIR?=	${PREFIX}/www/cgi-bin
DATADIR?=	/var/db/ovs
WWWROOT?=	${PREFIX}/www/data
OVS_USER?=	${WWWOWN}
OVS_GROUP?=	${WWWGRP}

USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	OVS_USER=${OVS_USER} OVS_GROUP=${OVS_GROUP}
PLIST_SUB=	CGIDIR=${CGIDIR:S,${PREFIX}/,,} WWWROOT=${WWWROOT:S,${PREFIX}/,,}

DOCS=		README CHANGES COPYING CHANGES.old README.old
.if !defined(NOPORTDOCS)
PORTDOCS=	${DOCS}
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DATADIR=/var/db/ovs		Where do you put RRD databases?"
	@${ECHO_MSG} "CGIDIR=${PREFIX}/www/cgi-bin      Where do you put cgi?"
	@${ECHO_MSG} "WWWROOT=${PREFIX}/www/data        Where do you put httpd's document root?"
	@${ECHO_MSG} "OVS_USER=www			User to run mailgraph (Default: ${WWWOWN})"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/ovs.cgi

do-install:
	@${MKDIR} ${CGIDIR}
	@${MKDIR} ${WWWROOT}/ovs
	@${MKDIR} ${DATADIR}
	@${CHOWN} -R ${OVS_USER}:${OVS_GROUP} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/ovs.pl ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/ovs.cgi ${CGIDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/ovs.css ${WWWROOT}/ovs
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
