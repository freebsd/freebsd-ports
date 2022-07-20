PORTNAME=	ctcs
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/dtorrent/${PORTNAME}/${PORTVERSION}

MAINTAINER=	dereckson@gmail.com
COMMENT=	CTorrent monitoring and managing interface

USES=		perl5 shebangfix
USE_PERL5=	run

SHEBANG_FILES=	ctcs

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	readme.txt
PLIST_FILES=	bin/ctcs

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ctcs ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
