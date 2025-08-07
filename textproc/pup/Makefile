PORTNAME=	pup
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0-10
DISTVERSIONSUFFIX=	-g681d7bb
PORTREVISION=	29
CATEGORIES=	textproc
PATCH_SITES=	https://github.com/ericchiang/pup/pull/
PATCHFILES=	107.patch:-p1 \
		142.patch:-p1

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command-line jq-like HTML parser using CSS selectors
WWW=		https://github.com/ericchiang/pup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	gdiff:textproc/diffutils

USES=		go:modules python:test shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ericchiang
GH_TUPLE=	fatih:color:v1.0.0:fatih_color/vendor/github.com/fatih/color \
		golang:net:4d38db76854b:golang_net/vendor/golang.org/x/net \
		golang:sys:a646d33e2ee3:golang_sys/vendor/golang.org/x/sys \
		golang:text:0a5a09ee4409:golang_text/vendor/golang.org/x/text \
		mattn:go-colorable:v0.0.5:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:56b76bdf51f7:mattn_go_isatty/vendor/github.com/mattn/go-isatty
SHEBANG_FILES=	tests/run.py

TEST_ENV=	PATH="${STAGEDIR}${PREFIX}/bin:${PATH}"

PLIST_FILES=	bin/pup
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run.py > test_results.txt
	cd ${WRKSRC}/tests && ${DIFF} expected_output.txt test_results.txt

.include <bsd.port.mk>
