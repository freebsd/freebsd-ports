PORTNAME=	cast2gif
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0-5
DISTVERSIONSUFFIX=	-g7373161
PORTREVISION=	17
CATEGORIES=	textproc

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Tool to render Asciinema cast files to GIFs
WWW=		https://github.com/katharostech/cast2gif

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cargo gmake
USE_GITHUB=	yes
GH_ACCOUNT=	katharostech

PLIST_FILES=	bin/cast2gif

PORTDOCS=	README.md
PORTEXAMPLES=	example1.gif tutorial.gif

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
