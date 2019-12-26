# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yatex
PORTVERSION=	1.82
CATEGORIES?=	print elisp
MASTER_SITES=	http://www.yatex.org/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Yet Another LaTeX mode and html mode on Emacs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKDIR}/LICENSE

USES=		dos2unix emacs

EMACS_NO_DEPENDS=	yes

NO_BUILD=	yes
SUB_FILES=	pkg-message yatex-startup.el
SUB_LIST=	EMACS_SITE_LISPDIR="${EMACS_SITE_LISPDIR}"

OPTIONS_DEFINE=	DOCS

PORTDOCS=	00readme readme.meadow.j yatex.new yatexj.tex yatex.ref	\
		yahtmlj.tex htmlqa yatexadd.doc yatexgen.doc qanda \
		yatexe.tex htmlqa.eng yahtmle.tex yatexref.eng qanda.eng
INFO=		yahtmle yahtmlj yatexe yatexj

ELFILES=yahtml.el yatex.el yatex19.el yatex23.el yatexadd.el		\
	yatexenv.el yatexflt.el yatexgen.el yatexhie.el yatexhks.el	\
	yatexhlp.el yatexlib.el yatexm-o.el yatexmth.el yatexpkg.el	\
	yatexprc.el yatexsec.el

post-extract:
	${INSTALL_DATA} ${WRKSRC}/docs/* ${WRKSRC}
	${SED} -n "/(c)1991/,/^;;; Code:$$/p" \
	    < ${WRKSRC}/yatex.el > ${WRKDIR}/LICENSE

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/yatex
	cd ${WRKSRC} && ${INSTALL_DATA} \
	    ${ELFILES} \
	    ${WRKDIR}/yatex-startup.el \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/yatex
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/yatex/help
	cd ${WRKSRC}/help && ${INSTALL_DATA} \
	    YATEXHLP.jp YATEXHLP.eng \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/yatex/help
	for F in ${INFO}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$F \
		    ${STAGEDIR}${PREFIX}/${INFO_PATH}/$${F}.info; \
	done

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
