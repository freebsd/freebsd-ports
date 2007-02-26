# New ports collection makefile for:	snd-music-duplicates
# Date created:		2006-08-18
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	snd-music-duplicates
PORTVERSION=	1.9.8
PORTREVISION=	1
CATEGORIES=	multimedia java
MASTER_SITES=	http://www.pekarna.si/ \
		http://olofsson.de/mirror/distfiles/
DISTNAME=	seek_and_destroy_music_duplicates

MAINTAINER=	simon@olofsson.de
COMMENT=	Locate and remove duplicated music files

DEPRECATED=	Development has been ceased, successor is shareware.
EXPIRATION_DATE=	2007-03-01

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JARNAME=${PORTNAME}.jar

PLIST_FILES=	%%DATADIR%%/${PORTNAME}.jar \
		bin/${PORTNAME}
PLIST_DIRS=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/files/srdmusicduplicates-all.jar \
	${DATADIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
