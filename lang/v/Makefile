PORTNAME=	v
PORTVERSION=	0.3.4
CATEGORIES=	lang

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	V Programming Language
WWW=		https://vlang.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake

LDFLAGS+=	-lm

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

ALL_TARGET=	v
TEST_TARGET=	check

GH_ACCOUNT=	vlang
GH_TUPLE=	vlang:vc:ec9b505:vc/vc
USE_GITHUB=	yes

do-install:
	# cd ${WRKSRC} && ./v symlink # Does not respect DESTDIR
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} &&	\
	${COPYTREE_SHARE} cmd ${STAGEDIR}${DATADIR} &&	\
	${COPYTREE_SHARE} thirdparty ${STAGEDIR}${DATADIR} &&	\
	${COPYTREE_SHARE} vlib ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/v ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/v.mod ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/v ${STAGEDIR}${PREFIX}/bin/v

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc &&	\
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples &&	\
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
