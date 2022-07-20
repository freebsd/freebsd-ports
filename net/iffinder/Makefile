PORTNAME=	iffinder
PORTVERSION=	1.38
CATEGORIES=	net
MASTER_SITES=	http://www.caida.org/tools/measurement/iffinder/download/

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for find other interfaces for same router

OPTIONS_DEFINE=	DOCS

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/iffinder
PORTDOCS=	README

MAKE_ARGS+=	CC="${CC}"

MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iffinder ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
