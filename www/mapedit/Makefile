# New ports collection makefile for:	mapedit
# Date created:		Fr   4 Apr 1997 17:45:31 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	mapedit
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.boutell.com/mapedit/http/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A WWW authoring tool to create clickable maps

RUN_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk11

JDK_VERSION=	1.1.8
NO_BUILD=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|!!LOCALBASE!!|${LOCALBASE}|" ${WRKSRC}/mapedit

pre-install:
	@${CAT} ${WRKSRC}/README.TXT
	@${ECHO_MSG} ""

do-install:
	${MKDIR} ${PREFIX}/lib/mapedit
	${CP} -r ${WRKSRC}/* ${PREFIX}/lib/mapedit
	${INSTALL_SCRIPT} ${PREFIX}/lib/mapedit/mapedit ${PREFIX}/bin
	${RM} -f ${PREFIX}/lib/mapedit/mapedit

.include <bsd.port.mk>
