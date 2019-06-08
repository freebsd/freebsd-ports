# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-mpfr
PORTVERSION=	0.5
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprecision floats for Pure

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

DEPRECATED=	Depends on expiring devel/llvm35
EXPIRATION_DATE=2019-08-31

USES=		pkgconfig pure
MAKE_ARGS=	libdir="${PREFIX}/lib"

PORTDOCS=	README
PORTEXAMPLES=	*
PLIST_FILES=	lib/pure/mpfr.pure \
		lib/pure/mpfr.so

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pure/mpfr.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
