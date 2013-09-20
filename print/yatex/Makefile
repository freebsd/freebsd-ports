# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yatex
PORTVERSION=	1.77
CATEGORIES?=	print elisp
MASTER_SITES=	http://www.yatex.org/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Yet Another LaTeX mode and html mode on Emacs

USE_DOS2UNIX=	yes
USE_EMACS=	yes
EMACS_NO_RUN_DEPENDS=	yes
EMACS_NO_BUILD_DEPENDS=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message yatex-startup.el
SUB_LIST=	EMACS_SITE_LISPDIR="${EMACS_SITE_LISPDIR}"

PORTDOCS=	00readme readme.meadow.j yatex.new yatexj.tex yatex.ref	\
		yahtmlj.tex htmlqa yatexadd.doc yatexgen.doc qanda \
		yatexe.tex htmlqa.eng yahtmle.tex yatexref.eng qanda.eng
INFO=		yahtmle yahtmlj yatexe yatexj

ELFILES=	comment.el yatex.el yatexadd.el yatexgen.el \
		yatexenv.el yatexlib.el \
		yatexmth.el yatexhks.el yatexhlp.el yatexprc.el \
		yatexm-o.el yatexsec.el  yatexpkg.el yatexhie.el yahtml.el \
		yatex19.el

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${INSTALL_DATA} ${WRKSRC}/docs/* ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}/yatex
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${ELFILES} ${PREFIX}/${EMACS_SITE_LISPDIR}/yatex
	${INSTALL_DATA} \
		${WRKDIR}/yatex-startup.el \
		${WRKSRC}/help/YATEXHLP.jp \
		${WRKSRC}/help/YATEXHLP.eng \
		${PREFIX}/${EMACS_SITE_LISPDIR}
	for F in ${INFO}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$F \
			${PREFIX}/${INFO_PATH}/$${F}.info; \
	done
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
