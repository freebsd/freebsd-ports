# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.4.5
CATEGORIES=	java www
MASTER_SITES=	ftp://ftp.sunet.se/pub/database/utils/orionserver/ \
		http://www.jollem.com/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${LOCALBASE}/linux-jdk1.3.0/bin/java:${PORTSDIR}/java/linux-jdk13

USE_ZIP=	YES
NO_BUILD=	YES
PLIST_SUB=	ORIONSUBDIR=${DISTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}
ORION_DESTDIR=	${PREFIX}/${DISTNAME}
ORION_LINKDIR=	${PREFIX}/${PORTNAME}
PORTTITLE=	Orion Server
RECURSIVE_CP=	${CP} -R

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${ORION_DESTDIR}
	@${RECURSIVE_CP} ${WRKSRC}/* ${ORION_DESTDIR}
	@${LN} -sf ${ORION_DESTDIR} ${ORION_LINKDIR}

post-install:
	@echo "${PORTTITLE} has been installed in ${ORION_LINKDIR} -> ${ORION_DESTDIR}."

.include <bsd.port.post.mk>
