PORTNAME=	mhddfs
PORTVERSION=	0.1.37
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://mhddfs.uvw.ru/downloads/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	proler@gmail.com
COMMENT=	Multi HDD [FUSE] File System
WWW=		http://mhddfs.uvw.ru/

USES=		fuse pkgconfig gmake
MAKE_ARGS=	WITHOUT_XATTR=1
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} share/man/man1/mhddfs.1.gz
PORTDOCS=	README ChangeLog

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|<sys/vfs.h>|<sys/statvfs.h>|' \
		${WRKSRC}/src/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
