PORTNAME=	zbackup
PORTVERSION=	1.4.4
PORTREVISION=	23
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Versatile deduplicating backup tool
WWW=		http://zbackup.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		liblzo2.so:archivers/lzo2

USES=		alias cmake:insource compiler:c++17-lang ssl
USE_GITHUB=	yes

CXXFLAGS+=	-Wno-dynamic-exception-spec
USE_CXXSTD=	c++17

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
