# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-mpfr
PORTVERSION=	0.5
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprecision floats for Pure

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

USES=		pkgconfig pure
MAKE_ARGS+=	libdir="${PREFIX}/lib"
PORTDOCS=	README
PORTEXAMPLES=	*
OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	lib/pure/mpfr.pure \
		lib/pure/mpfr.so

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pure/mpfr.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
