PORTNAME=	reproduce
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	AppJail image builder
WWW=		https://github.com/DtxdF/reproduce

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF

NO_BUILD=	yes

PLIST_FILES=	bin/appjail-reproduce \
		share/man/man1/reproduce.1.gz \
		share/man/man5/reproduce-spec.5.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/reproduce.1 ${STAGEDIR}${PREFIX}/share/man/man1/reproduce.1
	${INSTALL_MAN} ${WRKSRC}/reproduce-spec.5 ${STAGEDIR}${PREFIX}/share/man/man5/reproduce-spec.5

.include <bsd.port.mk>
