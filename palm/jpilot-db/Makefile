# ex:ts=8
# Ports collection makefile for:	jpilot-db
# Date created:			Sep 22, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jpilot-db
PORTVERSION=	1.3.20
PORTREVISION=	2
CATEGORIES=	palm java
MASTER_SITES=	http://chickenshick.com/jpilot-db/download/
EXTRACT_SUFX=	-ej.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A desktop app for pilot-db

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes
SUB_FILES=	jpilot-db.sh
SUB_LIST=	PKGNAME=${PKGNAME}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_FILES=	bin/jpilot-db \
		%%DATADIR%%/${PKGNAME}.jar
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jpilot-db.sh ${PREFIX}/bin/jpilot-db
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} ${DATADIR}/${PKGNAME}.jar

.include <bsd.port.mk>
