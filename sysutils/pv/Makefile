# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	pv
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ivarch.com/programs/sources/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A pipe throughput monitor

LICENSE=	ART20

CONFLICTS=	waon-[0-9]*

PROJECTHOST=	pipeviewer

USES=	tar:bzip2 gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pv man/man1/pv.1.gz

PORTDOCS=	README INSTALL NEWS PACKAGE TODO VERSION release-checklist

OPTIONS_DEFINE=	NLS LFS
OPTIONS_DEFAULT=	LFS
NLS_CONFIGURE_ON=	--enable-static-nls
NLS_CONFIGURE_OFF=	--disable-nls
LFS_CONFIGURE_ENABLE=	lfs

post-patch:
	@${CP} ${WRKSRC}/README ${WRKSRC}/doc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pv
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
