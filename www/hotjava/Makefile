# New ports collection makefile for:    Hotjava
# Version required:	3.0
# Date created:		1999/07/03
# Whom:			Jose Marques
#
# $FreeBSD$
#

DISTNAME=	hjb3_0-linux.sfx
PKGNAME=	hotjava-3.0
CATEGORIES=	www java
MASTER_SITES=
EXTRACT_SUFX=

MAINTAINER=	noway@nohow.demon.co.uk

RUN_DEPENDS=	${PREFIX}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk

EXTRACT_ONLY=

WRKSRC=		${WRKDIR}
JDK_VERSION=    1.1.8
NO_BUILD=	yes
NO_CDROM=	"See the licence"
RESTRICTED=	"Licenced for individual non-commercial use only"

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='You must fetch the linux version manually from http://java.sun.com/products/hotjava/ and copy the file to ${DISTDIR} and run make again.'
.endif

pre-patch:
	@${SED} -e s,/usr/bin/hotjava,${PREFIX}/bin/hotjava,g ${DISTDIR}/${DISTNAME} > ${WRKDIR}/${DISTNAME}

do-install:
	@${SH} ${WRKDIR}/${DISTNAME} ${PREFIX}/jdk${JDK_VERSION} ${PREFIX}/share/java

.include <bsd.port.post.mk>
