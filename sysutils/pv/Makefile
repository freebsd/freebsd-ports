PORTNAME=	pv
PORTVERSION=	1.8.13
CATEGORIES=	sysutils
MASTER_SITES=	https://www.ivarch.com/programs/sources/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Pipe throughput monitor
WWW=		https://www.ivarch.com/programs/pv.shtml

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/docs/COPYING

USES=		gmake

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFLICTS=	waon

PORTDOCS=	README.md INSTALL NEWS.md TODO.md

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${CP} ${WRKSRC}/README.md ${WRKSRC}/docs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pv

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
