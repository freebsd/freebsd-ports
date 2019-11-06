# Created by: Shinsuke Matsui <smatsui@karashi.org>
# $FreeBSD$

PORTNAME=	tinytinyhttpd
PORTVERSION=	0.0.11
CATEGORIES=	www
MASTER_SITES=	GHC

MAINTAINER=	smatsui@karashi.org
COMMENT=	Tiny tiny httpd

BROKEN=		unfetchable

USE_GITHUB=	yes
GH_ACCOUNT=	mattn

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/tthttpd
SUB_FILES=	example.conf
PORTDOCS=	README example.conf ChangeLog
OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tthttpd ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/example.conf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
