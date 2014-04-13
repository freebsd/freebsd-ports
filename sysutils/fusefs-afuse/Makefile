# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	afuse
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ak@FreeBSD.org
COMMENT=	File system automounting implemented in user-space using FUSE

LICENSE=	GPLv2

USES=		fuse pkgconfig
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS ChangeLog README
PLIST_FILES=	bin/${PORTNAME} man/man1/afuse.1.gz

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/afuse.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
