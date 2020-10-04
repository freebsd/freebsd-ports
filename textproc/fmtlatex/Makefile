# $FreeBSD$

PORTNAME=	fmtlatex
DISTVERSION=	g20130930
CATEGORIES=	textproc perl5

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Reformat LaTeX documents suitable for version control

LICENSE=	GPLv2+

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	loopspace
GH_TAGNAME=	e76acd9
SHEBANG_FILES=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	Bugs ChangeLog

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
