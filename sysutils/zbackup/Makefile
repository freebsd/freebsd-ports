# $FreeBSD$

PORTNAME=	zbackup
PORTVERSION=	1.4.4
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Versatile deduplicating backup tool

LICENSE=	GPLv2

LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		liblzo2.so:archivers/lzo2

BROKEN_powerpc64=	fails to compile: metadata_lite.h: class 'google::protobuf::internal::InternalMetadataWithArenaLite' does not have any field named 'InternalMetadataWithArenaBase'

USES=		alias cmake ssl
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/zbackup
PORTDOCS=	README.md

post-patch:
	@${REINPLACE_CMD} -e 's| CHECK(| ZBACKUP_CHECK(|' ${WRKSRC}/*.cc ${WRKSRC}/*.hh ${WRKSRC}/tests/*/*.cc

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/zbackup ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
