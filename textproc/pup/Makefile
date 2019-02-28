# $FreeBSD$

PORTNAME=	pup
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0-9
DISTVERSIONSUFFIX=	-g1c3cffd
CATEGORIES=	textproc

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command-line jq-like HTML parser using CSS selectors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go python:2.7,test shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ericchiang
SHEBANG_FILES=	tests/run.py

PLIST_FILES=	bin/pup
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-test:
	@${REINPLACE_CMD} 's|^python |${PYTHON_VERSION} |' ${WRKSRC}/tests/test
	@${REINPLACE_CMD} "s|pup |${STAGEDIR}/bin/pup |" ${WRKSRC}/tests/run.py

	# Disable broken tests.
	@${REINPLACE_CMD} "/^json{}$$/d" ${WRKSRC}/tests/cmds.txt
	@${REINPLACE_CMD} "/ json{}$$/d" ${WRKSRC}/tests/expected_output.txt
	@${REINPLACE_CMD} "/^#toc li + a json{}$$/d" ${WRKSRC}/tests/cmds.txt
	@${REINPLACE_CMD} "/ #toc li + a json{}$$/d" ${WRKSRC}/tests/expected_output.txt

do-test:
	cd ${WRKSRC}/tests && ${SH} ./test
	cd ${GO_WRKSRC} && ${SETENV} ${GO_ENV} ${GO_CMD} test

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
