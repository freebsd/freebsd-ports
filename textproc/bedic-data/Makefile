# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bedic-data
PORTVERSION=	0.1.b1
CATEGORIES=	textproc
MASTER_SITES=	SF/kbedic/Dictionary%20Data/1.0
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data (dictionary) files for the kbedic and cbedic ports

BROKEN=		unfetchable

NO_BUILD=	yes
NO_ARCH=	yes

DICT_ALL=	buleng.dat engbul.dat
DICT_DIR?=	${PREFIX}/share
DICTIONARIES?=	${DICT_ALL}
PLIST_FILES=	${DICTIONARIES:S,^,share/,}

pre-fetch:
	@${ECHO_MSG} "You may set the DICTIONARIES variable to specify which dictionaries"
	@${ECHO_MSG} "should be installed; currently, it is set to ${DICTIONARIES}"
	@${ECHO_MSG} "Set it to one or more of the following: ${DICT_ALL}"

do-install:
	@${MKDIR} ${STAGEDIR}${DICT_DIR}
	${INSTALL} ${DICTIONARIES:S,^,${WRKSRC}/,} ${STAGEDIR}${DICT_DIR}/

.include <bsd.port.mk>
