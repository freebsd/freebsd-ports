PORTNAME=	ess
DISTVERSION=	25.01.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://ess.r-project.org/ \
		http://stat.ethz.ch/ESS/downloads/ess/ \
		https://raw.githubusercontent.com/JuliaEditorSupport/:JULIA
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTFILES=	ess-25.01.0.tgz \
		julia-emacs/refs/heads/master/julia-mode.el:JULIA \
		julia-emacs/refs/heads/master/julia-mode-latexsubs.el:JULIA
EXTRACT_ONLY=	${DISTNAME}.tgz

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	R support for Emacsen
WWW=		https://ess.r-project.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	R:math/R

USES=		emacs gmake makeinfo perl5 tar:tgz
USE_PERL5=	build

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/emacs/site-lisp/ess/
	@${CP} ${WRKSRC}/lisp/*.el  ${STAGEDIR}${PREFIX}/share/emacs/site-lisp/ess/
	@${CP} ${WRKSRC}/lisp/*.elc ${STAGEDIR}${PREFIX}/share/emacs/site-lisp/ess/
	${INSTALL_DATA} ${WRKSRC}/doc/info/ess.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/ess/
	(cd ${WRKSRC}/etc && ${CP} ess-julia.jl ess-sas-sh-command \
		${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/ess/)
	${CP} -R ${WRKSRC}/etc/ESSR \
		${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/ess/
	${CP} -R ${WRKSRC}/etc/icons \
		${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/ess/

.include <bsd.port.mk>
