# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yatex
PORTVERSION=	1.77
PORTREVISION=	4
CATEGORIES?=	print elisp
MASTER_SITES=	http://www.yatex.org/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Yet Another LaTeX mode and html mode on Emacs

BROKEN=		unfetchable

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

ELFILES=	comment.el yatex.el yatexadd.el yatexgen.el \
		yatexenv.el yatexlib.el \
		yatexmth.el yatexhks.el yatexhlp.el yatexprc.el \
		yatexm-o.el yatexsec.el  yatexpkg.el yatexhie.el yahtml.el \
		yatex19.el

post-extract:
	@${INSTALL_DATA} ${WRKSRC}/docs/* ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/yatex
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${ELFILES} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/yatex
	${INSTALL_DATA} \
		${WRKDIR}/yatex-startup.el \
		${WRKSRC}/help/YATEXHLP.jp \
		${WRKSRC}/help/YATEXHLP.eng \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	for F in ${INFO}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$F \
			${STAGEDIR}${PREFIX}/${INFO_PATH}/$${F}.info; \
	done
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
