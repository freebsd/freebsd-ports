PORTNAME=	ox-gfm.el
PORTVERSION=	1.0p20231215.1901
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pat@patmaddox.com
COMMENT=	Github Flavored Markdown exporter for Org Mode
WWW=		https://github.com/larstvei/ox-gfm

LICENSE=	GPLv3+

USES=			emacs
EMACS_NO_DEPENDS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	larstvei
GH_PROJECT=	ox-gfm
GH_TAGNAME=	4f774f1

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
