# $FreeBSD$

PORTNAME=	zbackup
PORTVERSION=	1.4.4
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/zbackup/zbackup/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Versatile deduplicating backup tool

LICENSE=	GPLv2

LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		liblzo2.so:archivers/lzo2

USES=		alias cmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/zbackup
PORTDOCS=	README.md

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/zbackup ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
