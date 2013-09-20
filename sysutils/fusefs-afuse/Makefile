# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	afuse
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File system automounting implemented in user-space using FUSE

LICENSE=	GPLv2

USES=		fuse pkgconfig
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README
PLIST_FILES=	bin/${PORTNAME}
MAN1=		afuse.1
OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}
SUB_FILES=	pkg-message
.endif

.include <bsd.port.mk>
