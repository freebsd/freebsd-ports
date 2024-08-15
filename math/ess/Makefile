PORTNAME=	ess
DISTVERSION=	24.01.1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://ess.r-project.org/ \
		http://stat.ethz.ch/ESS/downloads/ess/
DISTNAME=	ESS-${DISTVERSION}
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	R support for Emacsen
WWW=		https://ess.r-project.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	R:math/R

USES=		emacs gmake makeinfo perl5
USE_PERL5=	build

NO_ARCH=	yes

#WRKSRC=		${WRKDIR}/ESS-${DISTVERSION}

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

post-patch:
	@${REINPLACE_CMD} -e \
		's|sed -i|sed -i .orig|g' ${WRKSRC}/Makefile
#	@${REINPLACE_CMD} -e \
#		's|^DESTDIR|#DESTDIR| ; \
#		 s|^PREFIX|#PREFIX| ; \
#		 s|=$$(PREFIX)|=$$(DESTDIR)$$(PREFIX)|' ${WRKSRC}/Makeconf
	@${REINPLACE_CMD} -e \
			's|info text|info text html pdf|' ${WRKSRC}/doc/Makefile
	# JULIAS disabled, because it downloads .el files for testing
	@${REINPLACE_CMD} -e '/^.PHONY: julia/,+3d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^JULIAS/d' ${WRKSRC}/lisp/Makefile
	@${REINPLACE_CMD} -e 's/ $$(JULIAS)//' ${WRKSRC}/lisp/Makefile
	@${REINPLACE_CMD} -e '/^$$(JULIAS):/,+4d' ${WRKSRC}/lisp/Makefile

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
