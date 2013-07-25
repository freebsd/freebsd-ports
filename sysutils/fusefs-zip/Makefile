# $FreeBSD$

PORTNAME=	fuse-zip
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	olevole@olevole.ru
COMMENT=	FUSE filesystem to mount ZIP archives with write support

LICENSE=	LGPL3

LIB_DEPENDS=	zip:${PORTSDIR}/archivers/libzip
BUILD_DEPENDS=	libzip>=0.11.1:${PORTSDIR}/archivers/libzip

USE_GMAKE=	yes
USES=		fuse pkgconfig

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1
PORTDOCS=	README TODO changelog

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-build:
	(cd ${WRKSRC} && ${GMAKE} -C lib && \
		${GMAKE} CXXFLAGS="-I${LOCALBASE}/include")

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
