PORTNAME=	v
PORTVERSION=	0.4.7
CATEGORIES=	lang

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	V Programming Language
WWW=		https://vlang.io/ \
		https://github.com/vlang/v

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake

ALL_TARGET=	v
LDFLAGS+=	-lm
TEST_TARGET=	check

USE_GITHUB=	yes
GH_TUPLE=	vlang:v:${PORTVERSION} \
		vlang:vc:8c681ed:vc/vc

PORTSCOUT=	limit:^[0-9\.]*$$

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

# maintainer section:

MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	@${ECHO_CMD} "bin/v" > ${MS_PLIST}
	@cd ${WRKSRC}/ && ${LS} *.md | ${SED} 's|^|%%PORTDOCS%%%%DOCSDIR%%/|' >> ${MS_PLIST}
	@cd ${WRKSRC}/doc/ && ${FIND} -s . -type f | ${SED} 's|^\.|%%PORTDOCS%%%%DOCSDIR%%|' >> ${MS_PLIST}
	@cd ${WRKSRC}/examples/ && ${FIND} -s . -type f | ${SED} 's|^\.|%%PORTEXAMPLES%%%%EXAMPLESDIR%%|' >> ${MS_PLIST}
	@cd ${WRKSRC}/cmd/ && ${FIND} -s . -type f | ${SED} 's|^\.|%%DATADIR%%/cmd|' >> ${MS_PLIST}
	@cd ${WRKSRC}/thirdparty/ && ${FIND} -s . -type f | ${SED} 's|^\.|%%DATADIR%%/thirdparty|' >> ${MS_PLIST}
	@${ECHO_CMD} "%%DATADIR%%/v" >> ${MS_PLIST}
	@${ECHO_CMD} "%%DATADIR%%/v.mod" >> ${MS_PLIST}
	@cd ${WRKSRC}/vlib/ && ${FIND} -s . -type f | ${SED} 's|^\.|%%DATADIR%%/vlib|' >> ${MS_PLIST}
	@${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
