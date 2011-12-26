# New ports collection makefile for:	x10
# Date created:		2011-10-12
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	x10
PORTVERSION=	2.2.1
CATEGORIES=	lang devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jwbacon@tds.net
COMMENT=	Object-oriented parallal programming language

USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes

USE_LDCONFIG=	${PREFIX}/stdlib/lib

# Can't have USE_GMAKE with USE_ANT: They imply conflicting do-build actions.
BUILD_DEPENDS+=	gmake:${PORTSDIR}/devel/gmake \
		bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/x10.dist

post-patch:
	${REINPLACE_CMD} -e 's/value="make"/value="gmake"/g' \
		${WRKDIR}/x10.runtime/build.xml

do-install:
.for f in X10Launcher apgas precommit x10 x10c x10c++ x10j
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/stdlib
	${INSTALL_DATA} ${WRKSRC}/etc/* ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib
	${CP} -R ${WRKSRC}/stdlib/* ${PREFIX}/stdlib
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
