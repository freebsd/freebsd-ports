PORTNAME=	nn
PORTVERSION=	6.7.3
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.nndev.org/pub/nn-${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Menu based USENET newsreader

BROKEN_aarch64=	Fails to link: missing sbrk
BROKEN_riscv64=	Fails to link: missing sbrk

SUB_FILES=	pkg-message

USES=		tar:Z
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -Iconf -fcommon" LDFLAGS="${LDFLAGS} -s"

pre-patch:
	@${CP} ${WRKSRC}/config.h-dist ${WRKSRC}/config.h.unparsed

pre-build:
	@${SED} 's#SUB_PREFIX#${PREFIX}#; s#SUB_MANPREFIX#${MANPREFIX}#' \
		${WRKSRC}/config.h.unparsed > ${WRKSRC}/config.h

post-build:
	@${REINPLACE_CMD} 's#${PREFIX}#$${DESTDIR}&#' ${WRKSRC}/inst

post-install:
	${INSTALL_DATA} ${FILESDIR}/nntp_domain.dist \
			${FILESDIR}/nntp_server.dist \
			${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
