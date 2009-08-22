# New ports collection makefile for:	bedic-data
# Date created:			15 April 2002
# Whom:				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bedic-data
PORTVERSION=	0.1.b1
CATEGORIES=	textproc
MASTER_SITES=	SF/kbedic/Dictionary%20Data/1.0
DISTNAME=	${PORTNAME}

MAINTAINER=	todorov@freebsd-bg.org
COMMENT=	Data (dictionary) files for the kbedic and cbedic ports

NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist

DICT_ALL=	buleng.dat engbul.dat
DICT_DIR?=	${PREFIX}/share
DICTIONARIES?=	${DICT_ALL}

pre-fetch:
		@${ECHO_MSG} "You may set the DICTIONARIES variable to specify which dictionaries"
		@${ECHO_MSG} "should be installed; currently, it is set to ${DICTIONARIES}"
		@${ECHO_MSG} "Set it to one or more of the following: ${DICT_ALL}"

pre-install:
		@${ECHO_CMD} ${DICTIONARIES} | ${TR} ' ' '\n' | ${SED} 's,^,share/,' > ${PLIST}

do-install:
		${MKDIR} ${DICT_DIR}
		${INSTALL} ${DICTIONARIES:S,^,${WRKSRC}/,} ${DICT_DIR}/

.include <bsd.port.mk>
