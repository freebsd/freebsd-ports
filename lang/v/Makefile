PORTNAME=	v
PORTVERSION=	0.3.4
CATEGORIES=	lang

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	V Programming Language
WWW=		https://vlang.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake

ALL_TARGET=	v
LDFLAGS+=	-lm
TEST_TARGET=	check

PORTDOCS=	*
PORTEXAMPLES=	*

GH_ACCOUNT=	vlang
GH_TUPLE=	vlang:vc:ec9b505:vc/vc
USE_GITHUB=	yes

PORTSCOUT=	skipv:weekly.*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	# cd ${WRKSRC} && ./v symlink # Does not respect DESTDIR
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/v ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/v.mod ${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/v ${STAGEDIR}${PREFIX}/bin/v
	cd ${WRKSRC} && ${COPYTREE_SHARE} cmd ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} thirdparty ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} vlib ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
