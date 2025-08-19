PORTNAME=	quarto # quarto also requires some Linux base to be installed, for example linux_base-rl9
DISTVERSION=	1.7.30
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/quarto-dev/quarto-cli/releases/download/v${DISTVERSION}/
DISTFILES=	quarto-${DISTVERSION}-linux-amd64.tar.gz # same for all architectures

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific and technical publishing system
WWW=		https://quarto.org \
		https://github.com/quarto-dev/quarto-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC_repo}/COPYRIGHT

# the recommended dependency versions are in the file 'configuration'
RUN_DEPENDS=	bash:shells/bash \
		deno:www/deno \
		esbuild:devel/esbuild \
		hs-pandoc>0:textproc/hs-pandoc \
		typst:textproc/typst \
		deno-dom>0:www/deno-dom \
		tex-xetex>0:print/tex-xetex \
		rubygem-dartsass>0:textproc/rubygem-dartsass \
		${PYTHON_PKGNAMEPREFIX}jupyter>0:devel/py-jupyter@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pipenv>0:devel/py-pipenv@${PY_FLAVOR} \
		${JULIA_RUN_DEPENS} \
		${R_RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		python

USE_GITHUB=	nodefault
GH_TUPLE=	quarto-dev:quarto-cli:v${DISTVERSION}:repo/repo # only for tests

WRKSRC_repo=	${WRKSRC}/repo

XARCH!=		uname -m

NO_BUILD=	yes

PLIST_SUB+=	XARCH=${XARCH}

OPTIONS_GROUP=			DEPENDENCIES
OPTIONS_GROUP_DEPENDENCIES=	JULIA R

JULIA_DESC=			Install Julia dependency
JULIA_RUN_DEPENS=		julia:lang/julia

R_DESC=				Install R dependency
R_RUN_DEPENDS=			R:math/R \
				R-cran-knitr>0:print/R-cran-knitr \
				R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

post-patch:
	# replace tokens in the quarto executable and in run-tests.sh
	${REINPLACE_CMD} -i '' \
		-e 's|%%SCRIPT_PATH%%|${DATADIR}/bin|; s|%%ARCH_DIR%%|${XARCH}|' \
		${WRKSRC}/bin/quarto
	${REINPLACE_CMD} \
		-e ' \
			s|%%SCRIPT_PATH%%|${STAGEDIR}${DATADIR}/bin|; \
			s|%%ARCH_DIR%%|${XARCH}|; \
			s|%%REPO%%|${WRKSRC}/repo|; \
			s|$$DENO_DIR|${LOCALBASE}/bin|; \
			s|export QUARTO_SHARE_PATH=.*|export QUARTO_SHARE_PATH=${WRKSRC_repo}/src/resources|; \
		' \
		${WRKSRC}/repo/tests/run-tests.sh
	# replace python3 with the real python executable path
	${REINPLACE_CMD} -i '' -e 's|"python3"|"${PYTHON_CMD}"|' ${WRKSRC}/bin/quarto.js

do-install:
	# copy files from the tarball
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} bin ${STAGEDIR}${DATADIR} && \
		${COPYTREE_SHARE} share ${STAGEDIR}${DATADIR}
	# remove unnecessary files
	${RM} ${STAGEDIR}${DATADIR}/bin/quarto.orig
	# adjust architecture
	${MV} ${STAGEDIR}${DATADIR}/bin/tools/x86_64 ${STAGEDIR}${DATADIR}/bin/tools/${XARCH}
	cd ${STAGEDIR}${DATADIR}/bin/tools && ${LN} -s amd64 x86_64
	# create symlink
	${RLN} ${STAGEDIR}${DATADIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# substitute linux binaries with native ones
.for exe in deno esbuild pandoc typst
	${TOUCH} ${STAGEDIR}${PREFIX}/bin/${exe}
	${RM} ${STAGEDIR}${DATADIR}/bin/tools/${XARCH}/${exe}
	${RLN} ${STAGEDIR}${PREFIX}/bin/${exe} ${STAGEDIR}${DATADIR}/bin/tools/${XARCH}/${exe}
	${RM} ${STAGEDIR}${PREFIX}/bin/${exe}
.endfor
	${RM} ${STAGEDIR}${DATADIR}/bin/tools/${XARCH}/deno_dom/libplugin.so
	${RMDIR} ${STAGEDIR}${DATADIR}/bin/tools/${XARCH}/deno_dom
	${REINPLACE_CMD} -i '' \
		-e 's|export DENO_DOM_PLUGIN=.*|export DENO_DOM_PLUGIN=${LOCALBASE}/lib/deno-plugins/deno_dom.so|' \
		${STAGEDIR}${DATADIR}/bin/quarto
	# make quarto an executable
	${CHMOD} +x ${STAGEDIR}${DATADIR}/bin/quarto
	# replace Linux binary for dart-sass with the binary provided by the rubygem-dartsass package
	${RM} -r ${STAGEDIR}${DATADIR}/bin/tools/${XARCH}/dart-sass
	${MKDIR} ${STAGEDIR}${DATADIR}/bin/tools/${XARCH}/dart-sass
	${LN} -s \
		${LOCALBASE}/lib/ruby/gems/*/gems/dartsass-*/exe/linux/sass \
		${STAGEDIR}${DATADIR}/bin/tools/${XARCH}/dart-sass/sass

do-test: # tests fail to run with: RuntimeError: Failed to lock Pipfile.lock!
	@cd ${WRKSRC_repo}/tests && \
		${SETENV} QUARTO_TESTS_FORCE_NO_PIPENV=yes \
		./run-tests.sh smoke/extensions/extension-render-doc.test.ts

test-quick: install
.for test in py-line-plot-on-a-polar-axis r-airquality julia-fig-parametric
	@cd ${TEST_WRKSRC} && \
		${CP} ${FILESDIR}/example-${test}.qmd . && \
		${PORTNAME} render example-${test}.qmd --to pdf && \
		okular example-${test}.pdf
	# the Julia example above fails, see https://github.com/quarto-dev/quarto-cli/issues/12468
.endfor

.include <bsd.port.mk>
