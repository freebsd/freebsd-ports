# $FreeBSD$

PORTNAME=	ctl-sat
DISTVERSION=	g20200210
CATEGORIES=	math

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	CTL (Computation Tree Logic) SAT solver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	nicolaprezza
GH_PROJECT=	CTLSAT
GH_TAGNAME=	6de41e0

PLIST_FILES=	bin/ctl-sat

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-build:
	@${RM} ${WRKSRC}/ctl-sat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctl-sat ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
