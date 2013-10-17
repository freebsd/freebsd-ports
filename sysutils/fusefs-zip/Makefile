# $FreeBSD$

PORTNAME=	fuse-zip
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	olevole@olevole.ru
COMMENT=	FUSE filesystem to mount ZIP archives with write support

LICENSE=	LGPL3

LIB_DEPENDS=	libzip.so:${PORTSDIR}/archivers/libzip
BUILD_DEPENDS=	libzip>=0.11.1:${PORTSDIR}/archivers/libzip

USES=		gmake fuse pkgconfig

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	README TODO changelog

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
