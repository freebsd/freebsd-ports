# New ports collection makefile for:	frostwire
# Date created:				2007-04-20
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	frostwire
PORTVERSION=	4.17.0
CATEGORIES=	net-p2p java
MASTER_SITES=	http://main2.frostwire.com/frostwire/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.noarch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Java based Gnutella and Bittorrent client

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/.7/.6/}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}.sh

post-extract:
	@cd ${WRKSRC} && ${RM} -f *.so *.sh COPYING && \
		${MV} changelog frostwire.desktop ..
	@${FIND} ${WRKSRC} -type d -name .svn -print0 | ${XARGS} -0 ${RM} -rf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/changelog ${DOCSDIR}
.endif

.include <bsd.port.mk>
