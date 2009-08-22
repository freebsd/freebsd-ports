# New ports collection makefile for:	ipacco
# Date created:		25 June 2006
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	ipacco
PORTVERSION=	0.2.0.1
PORTREVISION=	5
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web based tool to analyze Cisco IP accounting data

RUN_DEPENDS=	${LOCALBASE}/include/tclExtend.h:${PORTSDIR}/lang/tclX \
		${LOCALBASE}/lib/mysqltcl-3.05/pkgIndex.tcl:${PORTSDIR}/databases/mysqltcl \
		dtplite:${PORTSDIR}/devel/tcllib

NO_BUILD=	yes
USE_PHP=	mysql gd
USE_TCL_RUN=	yes

IPACCO?=	www/${PORTNAME}
IPACCO_WEB=	${PREFIX}/${IPACCO}
PLIST_SUB+=	IPACCO_WEB=${IPACCO}
SUB_LIST+=	IPACCO_WEB=${IPACCO} \
		PORTDOCS=${PORTDOCS} \
		PORTNAME=${PORTNAME}

SUB_FILES=	pkg-message

.if !defined(NOPORTDOCS)
PORTDOCS1=	INSTALL.html INSTALL.txt RELNOTES.html RELNOTES.txt
PORTDOCS2=	README.html README.txt LICENSE CreateDB.sql
.endif

pre-install:
	@${FIND} ${WRKSRC} -name '*.bak' -type f -print0 | ${XARGS} -0 ${RM} -f

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/tclsh|${TCLSH}|' \
	    ${WRKSRC}/datapump/ipacco-datapump.tcl
	@${REINPLACE_CMD} -e 's|\<?=|\<?php print|g' \
	    ${WRKSRC}/html/*.php

do-install:
	-@${MKDIR} ${IPACCO_WEB}
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	@${CP} -R ${WRKSRC}/html/* ${IPACCO_WEB}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${IPACCO_WEB}
	@${INSTALL_DATA} ${WRKSRC}/datapump/ipacco-datapump.cfg \
		${PREFIX}/etc/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/datapump/ipacco-datapump.tcl \
		${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS1}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.for f in ${PORTDOCS2}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
