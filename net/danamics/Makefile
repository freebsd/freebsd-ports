# New ports collection makefile for:	danamics
# Date created:		18 March 2003
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	danamics
PORTVERSION=	1.1
CATEGORIES=	net java
MASTER_SITES=	ftp://ftp.cs.uct.ac.za/pub/FreeBSD/distfiles-local/

MAINTAINER=	mwest@uct.ac.za
COMMENT=	Petri Net editor for correctness and performance analysis

USE_JAVA=	1.1+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/DaNAMiCS

.include <bsd.port.pre.mk>

PLIST=		${WRKDIR}/plist

SORT?=		/usr/bin/sort

do-install:
	${MKDIR} ${PREFIX}/danamics
	${CP} -R ${WRKSRC}/* ${PREFIX}/danamics

	cd ${PREFIX}; ${FIND} danamics -type f \
		| ${SORT} >${PLIST}
	cd ${PREFIX}; ${FIND} danamics -type d \
		| ${SORT} -r | ${SED} -e 's|^|@dirrm |' >>${PLIST}

	${SED} \
		-e s,%%PREFIX%%,${PREFIX},g \
		< ${FILESDIR}/danamics.sh > ${PREFIX}/bin/danamics; \
	${CHMOD} a+x ${PREFIX}/bin/danamics

	${ECHO} bin/danamics >>${PLIST}

.include <bsd.port.post.mk>
