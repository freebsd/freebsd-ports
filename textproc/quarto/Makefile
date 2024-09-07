PORTNAME=	quarto
DISTVERSION=	1.6.9
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/quarto-dev/quarto-cli/releases/download/v${DISTVERSION}/
DISTFILES=	quarto-${DISTVERSION}-linux-amd64.tar.gz # same for all architectures

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific and technical publishing system
WWW=		https://quarto.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/repo/COPYRIGHT

RUN_DEPENDS=	bash:shells/bash \
		deno:www/deno \
		esbuild:devel/esbuild \
		hs-pandoc32>0:textproc/hs-pandoc32 \
		typst:textproc/typst \
		deno-dom>0:www/deno-dom \
		tex-xetex>0:print/tex-xetex \
		${LOCALBASE}/lib/ruby/gems/3.2/gems/dartsass-1.49.8/exe/linux/sass:textproc/rubygem-dartsass \
		${PYTHON_PKGNAMEPREFIX}jupyter>0:devel/py-jupyter@${PY_FLAVOR}

USES=		python

USE_GITHUB=	nodefault
GH_TUPLE=	quarto-dev:quarto-cli:v${DISTVERSION}:repo/repo # only for tests

XARCH!=		uname -m

PLIST_SUB+=	XARCH=${XARCH}

NO_BUILD=	yes

OPTIONS_DEFINE=	R

R_DESC=		Install R dependency
R_RUN_DEPENDS=	R:math/R \
		R-cran-knitr>0:print/R-cran-knitr
		#R-cran-rmarkdown>0:textproc/R-cran-rmarkdown # conflicts with hs-pandoc32

post-patch:
	# replace tokens in the quarto executable and in run-tests.sh
	${REINPLACE_CMD} -i '' \
		-e 's|%%SCRIPT_PATH%%|${DATADIR}/bin|; s|%%ARCH_DIR%%|${XARCH}|' \
		${WRKSRC}/bin/quarto
	${REINPLACE_CMD} \
		-e 's|%%SCRIPT_PATH%%|${STAGEDIR}${DATADIR}/bin|; s|%%ARCH_DIR%%|${XARCH}|; s|%%REPO%%|${WRKSRC}/repo|; s|$$DENO_DIR|${LOCALBASE}/bin|' \
		${WRKSRC}/repo/tests/run-tests.sh

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
		${LOCALBASE}/lib/ruby/gems/3.2/gems/dartsass-1.49.8/exe/linux/sass \
		${STAGEDIR}${DATADIR}/bin/tools/${XARCH}/dart-sass/sass

.include <bsd.port.mk>
