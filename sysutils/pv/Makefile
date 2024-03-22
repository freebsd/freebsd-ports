PORTNAME=	pv
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ivarch.com/programs/sources/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Pipe throughput monitor
WWW=		https://www.ivarch.com/programs/pv.shtml

LICENSE=	ART20

USES=	tar:bzip2 gmake

CONFLICTS=	waon

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
MAKE_ENV+=	LD=${LD}

PLIST_FILES=	bin/pv share/man/man1/pv.1.gz

PORTDOCS=	README.md INSTALL NEWS.md TODO.md

OPTIONS_DEFINE=	DOCS NLS LFS
OPTIONS_DEFAULT=	LFS
NLS_CONFIGURE_ON=	--enable-static-nls
NLS_CONFIGURE_OFF=	--disable-nls
LFS_CONFIGURE_ENABLE=	lfs

post-patch:
	@${CP} ${WRKSRC}/README.md ${WRKSRC}/doc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pv

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
