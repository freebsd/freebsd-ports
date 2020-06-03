# $FreeBSD$

PORTNAME=	zbackup
PORTVERSION=	1.4.4
PORTREVISION=	15
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Versatile deduplicating backup tool

LICENSE=	GPLv2

LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		liblzo2.so:archivers/lzo2

USES=		alias cmake:insource compiler:c++11-lang ssl
USE_CXXSTD=	c++11
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
