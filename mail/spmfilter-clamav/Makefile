# Created by: Axel Steiner <ast@treibsand.com>
# $FreeBSD$

PORTNAME=	spmfilter-clamav
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.spmfilter.org/attachments/download/59/

MAINTAINER=	ast@treibsand.com
COMMENT=	ClamAV plugin for spmfilter

BUILD_DEPENDS=	spmfilter>=0.4:${PORTSDIR}/mail/spmfilter

RUN_DEPENDS=	spmfilter>=0.4:${PORTSDIR}/mail/spmfilter

USES=		cmake pkgconfig
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"

USE_LDCONFIG=	${PREFIX}/lib/spmfilter

OPTIONS_DEFINE=	DEBUG

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=    -DENABLE_DEBUG=TRUE
.endif

MAN1=           ${PORTNAME}.1
MANCOMPRESSED=  yes

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' \
		${WRKSRC}/cmake/Modules/SMFMacros.cmake

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${DOCSDIR}/contrib
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/virus-notify.txt ${DOCSDIR}/contrib
.endif
.include <bsd.port.mk>
