# $FreeBSD$

PORTNAME=	zbackup
PORTVERSION=	1.3
CATEGORIES=	sysutils

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Versatile deduplicating backup tool

LICENSE=	GPLv2

LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

USES=		cmake
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/zbackup
PORTDOCS=	README.md

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/zbackup ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
