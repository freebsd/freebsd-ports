PORTNAME=	pv
PORTVERSION=	1.6.20
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ivarch.com/programs/sources/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Pipe throughput monitor

LICENSE=	ART20

USES=	tar:bzip2 gmake

CONFLICTS=	waon

GNU_CONFIGURE=	yes
MAKE_ENV+=	LD=${LD}

PLIST_FILES=	bin/pv man/man1/pv.1.gz

PORTDOCS=	README INSTALL NEWS PACKAGE TODO VERSION release-checklist

OPTIONS_DEFINE=	DOCS NLS LFS
OPTIONS_DEFAULT=	LFS
NLS_CONFIGURE_ON=	--enable-static-nls
NLS_CONFIGURE_OFF=	--disable-nls
LFS_CONFIGURE_ENABLE=	lfs

post-patch:
	@${CP} ${WRKSRC}/README ${WRKSRC}/doc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pv

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
