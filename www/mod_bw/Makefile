# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_bw
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://legacy.ivn.cl/files/source/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Bandwidth and Connection control per Virtual Host or Directory

LICENSE=	APACHE20

WRKSRC=		${WRKDIR}/mod_bw
USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

SRC_FILE=	mod_bw.c
PORTDOCS=	mod_bw.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
