# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phex
PORTVERSION=	3.4.2.116
PORTREVISION=	1
CATEGORIES=	net-p2p java
MASTER_SITES=	SF/${PORTNAME}/Phex%20Final%20Releases/Phex%20${PORTVERSION:R}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-platform and spyware-free Gnutella client

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PORTDOCS=	Phex_other.htm \
		Undocumented.htm

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/readme/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
