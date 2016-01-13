# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-xml
PORTVERSION=	0.7
CATEGORIES=	textproc
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure language interface for libxml2 and libxslt

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

USES=		pkgconfig pure
USE_GNOME=	libxml2 libxslt
PORTDOCS=	README
PORTEXAMPLES=	*
OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	lib/pure/xml.pure \
		lib/pure/xml.so

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pure/xml.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
