# New ports collection makefile for:	convey
# Date created:				2005-07-18
# Whom:					Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	convey
PORTVERSION=	0.3
CATEGORIES=	net java
MASTER_SITES=	http://convey.sourceforge.net/downloads/ \
		http://nivi.interfree.it/tmp/convey.sourceforge.net/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	An Instant Message (IM) program using the Jabber protocol

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_ANT=	yes
USE_JAVA=	yes

JAVA_VERSION=	1.3+

MAKE_ARGS=	-quiet

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
FIND_DIRS=	lib

SUB_FILES=	convey.sh

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/convey.sh ${PREFIX}/bin/convey
	cd ${WRKSRC} && ${FIND} ${FIND_DIRS} -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} ${FIND_DIRS} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

.include <bsd.port.post.mk>
