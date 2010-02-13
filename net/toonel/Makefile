# New ports collection makefile for:	toonel
# Date created:		2010-02-04
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	toonel
PORTVERSION=	0.0.50.50
CATEGORIES=	net java
MASTER_SITES=	http://www.toonel.net/generic/005050/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Tunneling with data compression

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.5+

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JARNAME=${DISTNAME}${EXTRACT_SUFX}

PLIST_FILES=	bin/${PORTNAME} ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
