# New ports collection makefile for:	duply
# Date created:		2010-09-25
# Whom:			Michael Ranner <michael@ranner.eu>
#
# $FreeBSD$
#

PORTNAME=	duply
PORTVERSION=	1.5.2.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/ftplicity/${PORTNAME}%20%28simple%20duplicity%29/1.5.x/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	michael@ranner.eu
COMMENT=	Shell front end for the duplicity backup tool

RUN_DEPENDS=	duplicity:${PORTSDIR}/sysutils/duplicity

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl.txt
NO_BUILD=	yes

PORTDOCS=	INSTALL.txt gpl.txt
PLIST_FILES=	bin/duply

post-patch:
	@${REINPLACE_CMD} -e "s,^#!/bin/bash,#!${LOCALBASE}/bin/bash,g" \
		-e "s,/etc/duply,${LOCALBASE}/etc/duply,g" \
		${WRKSRC}/duply

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/duply ${LOCALBASE}/bin/duply
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.	for i in ${PORTDOCS}
	  @${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.	endfor
.endif

.include <bsd.port.mk>
