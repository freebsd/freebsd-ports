# New ports collection makefile for:	pauker
# Date created:				11 November 2007
# Whom:					Alex Stangl <alex@stangl.us>
#
# $FreeBSD$
#

PORTNAME=	pauker
DISTVERSION=	1.8RC2
PORTREVISION=	1
CATEGORIES=	misc java
MASTER_SITES=	SF/${PORTNAME}/OldFiles
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	alex@stangl.us
COMMENT=	Java-based flashcard learning using the Leitner system

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar bin/${PORTNAME}

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${SED} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
	    -e "s:%%JAVAJARDIR%%:${JAVAJARDIR}:" \
	    -e "s:%%PORTNAME%%:${PORTNAME}:" \
	    ${FILESDIR}/pauker.sh > ${PREFIX}/bin/${PORTNAME}
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/${PORTNAME}
	@${CHMOD} a+rx ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
