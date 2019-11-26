# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	convey
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	net-im java
MASTER_SITES=	http://convey.sourceforge.net/downloads/ \
		http://nivi.interfree.it/tmp/convey.sourceforge.net/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Instant Message (IM) program using the Jabber protocol

USE_ANT=	yes
USE_JAVA=	yes

MAKE_ARGS=	-quiet

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
FIND_DIRS=	lib

SUB_FILES=	convey.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/convey.sh ${STAGEDIR}${PREFIX}/bin/convey
	cd ${WRKSRC} && ${FIND} ${FIND_DIRS} -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} ${FIND_DIRS} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;

.include <bsd.port.mk>
