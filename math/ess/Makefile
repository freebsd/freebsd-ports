PORTNAME=	ess
DISTVERSION=	26.01.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://ess.r-project.org/ \
		https://stat.ethz.ch/ESS/downloads/ess/ \
		https://raw.githubusercontent.com/JuliaEditorSupport/:JULIA
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}.tar.gz \
		julia-emacs/refs/heads/master/julia-mode.el:JULIA \
		julia-emacs/refs/heads/master/julia-mode-latexsubs.el:JULIA
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	R support for Emacsen
WWW=		https://ess.r-project.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	R:math/R

USES=		emacs:build gmake makeinfo perl5 tar:tgz
USE_PERL5=	build

CONFLICTS_INSTALL=	ess-emacs_*

NO_ARCH=	yes

INFO=		ess

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPTIONS_DEFINE:MDOCS}
BUILD_DEPENDS+=	makeinfo:print/texinfo \
		texi2html:textproc/texi2html
USES+=		tex
USE_TEX=	latex:build dvipsk:build
INSTALL_TARGET=	doc
.endif

post-extract:
	@${CP} -p ${DISTDIR}/julia-emacs/refs/heads/master/julia-mode*.el \
		${WRKSRC}/lisp/

post-patch:
	@${REINPLACE_CMD} -e \
		's|sed -i|sed -i .orig|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
			's|info text|info text html pdf|' ${WRKSRC}/doc/Makefile

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf         ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/refcard/*.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html   ${STAGEDIR}${DOCSDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/ess/
	@${CP} ${WRKSRC}/lisp/*.el  ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/ess/
	${INSTALL_DATA} ${WRKSRC}/doc/info/ess.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/ess/
	(cd ${WRKSRC}/etc && ${CP} ess-julia.jl ess-sas-sh-command \
		${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/ess/)
	${CP} -R ${WRKSRC}/etc/ESSR \
		${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/ess/
	${CP} -R ${WRKSRC}/etc/icons \
		${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/ess/

.include <bsd.port.mk>
