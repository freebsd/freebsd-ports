# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	ovs
PORTVERSION=	1.05
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.oav.net/openvisp/stats/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RRDtool frontend for mail statistics

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rrdtool>=0:databases/rrdtool \
		p5-File-Tail>=0:devel/p5-File-Tail

NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	ovs.pl ovs.cgi

CGIDIR?=	${PREFIX}/www/cgi-bin
DATADIR?=	/var/db/ovs
WWWROOT?=	${PREFIX}/www/data
OVS_USER?=	${WWWOWN}
OVS_GROUP?=	${WWWGRP}

USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	OVS_USER=${OVS_USER} OVS_GROUP=${OVS_GROUP}
PLIST_SUB=	CGIDIR=${CGIDIR:S,${PREFIX}/,,} WWWROOT=${WWWROOT:S,${PREFIX}/,,} \
		OVS_USER=${OVS_USER} OVS_GROUP=${OVS_GROUP}

PORTDOCS=	README CHANGES COPYING CHANGES.old README.old

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
	@${MKDIR} ${STAGEDIR}${CGIDIR}
	@${MKDIR} ${STAGEDIR}${WWWROOT}/ovs
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ovs.pl ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ovs.cgi ${STAGEDIR}${CGIDIR}
	${INSTALL_DATA} ${WRKSRC}/ovs.css ${STAGEDIR}${WWWROOT}/ovs
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in ${PORTDOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${STAGEDIR}${DOCSDIR}; \
	done

.include <bsd.port.mk>
