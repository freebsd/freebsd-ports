# New ports collection makefile for:	jakarta-ant
# Date created:		21 February 2001
# Whom:			ernst@jollem.com
#
# $FreeBSD$
#

PORTNAME=	xalan-j
PORTVERSION=	2.0.1
CATEGORIES=	java textproc
MASTER_SITES=	http://xml.apache.org/dist/${PORTNAME}/ \
		http://xml.apache.org/dist/old/${PORTNAME}/ \
		http://www.jollem.com/~ernst/
DISTNAME=	${PORTNAME}_2_0_1

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=    ${JAVAVM}:${PORTSDIR}/java/javavmwrapper

JAVAVM?=        ${LOCALBASE}/bin/javavm

NO_BUILD=	YES
PORTDESTDIR=	${PREFIX}/${PORTNAME}${PORTVERSION}

do-install:
	@${MKDIR} ${PORTDESTDIR}
	@${CP} -r ${WRKSRC}/* ${PORTDESTDIR}

.include <bsd.port.mk>
