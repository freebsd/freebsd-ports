PORTNAME=	scanbuttond
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	dthiele@gmx.net
COMMENT=	Daemon to monitor and configure modern scanner's buttons

LICENSE=	GPLv2

USES=		libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

SUB_FILES+=	pkg-message

pre-configure:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|-ldl||g'

pre-install:
	@if [ -f ${WRKSRC}/scripts/buttonpressed.sh ]; then \
		for na in buttonpressed.sh initscanner.sh; do \
			${MV} ${WRKSRC}/scripts/$$na ${WRKSRC}/scripts/$$na.sample ; \
		done; \
		${REINPLACE_CMD} -e 's|\.sh|.sh.sample|g' ${WRKSRC}/scripts/Makefile ; \
		${MV} ${WRKSRC}/backends/meta.conf ${WRKSRC}/backends/meta.conf.sample ; \
		${REINPLACE_CMD} -e 's|meta\.conf|meta.conf.sample|g' ${WRKSRC}/backends/Makefile ; \
	fi

.include <bsd.port.mk>
