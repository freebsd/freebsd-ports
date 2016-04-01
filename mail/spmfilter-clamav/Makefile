# Created by: Axel Steiner <ast@treibsand.com>
# $FreeBSD$

PORTNAME=	spmfilter-clamav
PORTVERSION=	0.2.3
CATEGORIES=	mail
MASTER_SITES=	http://www.spmfilter.org/files/

MAINTAINER=	ast@treibsand.com
COMMENT=	ClamAV plugin for spmfilter

BUILD_DEPENDS=	spmfilter>=0.6:mail/spmfilter
RUN_DEPENDS=	spmfilter>=0.6:mail/spmfilter

USES=		cmake pkgconfig
CMAKE_ARGS+=	--no-warn-unused-cli \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"

USE_LDCONFIG=	${PREFIX}/lib/spmfilter

OPTIONS_DEFINE=	DEBUG

DEBUG_CMAKE_ON=	-DENABLE_DEBUG=TRUE

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' \
		${WRKSRC}/cmake/Modules/SMFMacros.cmake

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/virus-notify.txt ${STAGEDIR}${DOCSDIR}/contrib

.include <bsd.port.mk>
