PORTNAME=	fuse-zip
PORTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://bitbucket.org/agalanin/fuse-zip/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE filesystem to mount ZIP archives with write support
WWW=		https://bitbucket.org/agalanin/fuse-zip/

LICENSE=	LGPL3

LIB_DEPENDS=	libzip.so:archivers/libzip
BUILD_DEPENDS=	libzip>=0.11.1:archivers/libzip

USES=		gmake fuse pkgconfig

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	README.md changelog

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
