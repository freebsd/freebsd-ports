# New ports collection makefile for: YaTeX
# Date created:		98/11/17
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yatex
PORTVERSION=	1.73
PORTREVISION=	3
CATEGORIES?=	print elisp
MASTER_SITES=	http://www.yatex.org/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Yet Another LaTeX mode and html mode on Emacs

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
DESCR=		${PKGDIR}/pkg-descr
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
SUB_FILES=	pkg-install pkg-deinstall pkg-message yatex-startup.el
SUB_LIST=	TARGETNAME=${TARGETNAME} \
		VERSION=${PORTVERSION} \
		BASENAME=${BASENAME} \
		CAT=${CAT} \
		CP=${CP} \
		ECHO=${ECHO_CMD} \
		GREP=${GREP} \
		RM=${RM} \
		SED=${SED} \
		TOUCH=${TOUCH} \
		DO_NADA=${DO_NADA} \
		INFODIR=${INFODIR} \
		ELISPDIR=${ELISPDIR} \
		INFOFILES=${INFOFILES} \
		INFONODES="${INFONODES}" \
		INFONODEEXPS="${INFONODEEXPS}" \
		DIRSECTION="${DIRSECTION}" \
		EMACS_NAME=${EMACS_NAME}

USE_EMACS=	yes
EMACS_NO_RUN_DEPENDS=YES
EMACS_MASTERDIR_PKGFILES=YES
EMACS_PACKAGESDIR=${EMACS_LIBDIR}/site-packages

TARGETNAME=	YaTeX
DIRSECTION=	The Emacs editor and associated tools

# Note that 'INFODIR' is defined in bsd.info.mk

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == xemacs21)
EMACS_NO_BUILD_DEPENDS=	YES
INFODIR=	${PREFIX}/${EMACS_PACKAGESDIR}/info
ELISPDIR=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp
HELPDIR=	${PREFIX}/${EMACS_LIBDIR}/site-lisp
PLIST=		${PKGDIR}/pkg-plist.xemacs
MANIFEST=	MANIFEST.yatex
HELP=		help/YATEXHLP.eng
INFOFILES=	yatexe:yahtmle
INFONODES=	YaTeX:yahtml
INFONODEEXPS=	Yet Another tex-mode for Emacs.:Yet Another HTML mode.
.elif (${EMACS_PORT_NAME} == xemacs21-mule)
INFODIR=	${PREFIX}/${EMACS_PACKAGESDIR}/info
ELISPDIR=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp
HELPDIR=	${PREFIX}/${EMACS_LIBDIR}/site-lisp
PLIST=		${PKGDIR}/pkg-plist.xemacs-mule
MANIFEST=	MANIFEST.yatex
HELP=		help/YATEXHLP.jp help/YATEXHLP.eng
PORTDOCS=	00readme readme.meadow.j yatex.new yatexj.tex yatex.ref	\
		yahtmlj.tex htmlqa yatexadd.doc yatexgen.doc qanda
INFOFILES=	yatexj:yatexe:yahtmlj:yahtmle
INFONODES=	YaTeX-jp:YaTeX:yahtml-jp:yahtml
INFONODEEXPS=	Yet Another tex-mode for Emacs. (Japanese):Yet Another tex-mode for Emacs.:Yet Another HTML mode. (Japanese):Yet Another HTML mode.
.else
EMACS_NO_BUILD_DEPENDS=	YES
INFODIR=	${PREFIX}/info
PLIST=		${PKGDIR}/pkg-plist.emacs
ELISPDIR=	${PREFIX}/${EMACS_LIBDIR}/site-lisp
HELPDIR=	${ELISPDIR}
HELP=		help/YATEXHLP.jp help/YATEXHLP.eng
PORTDOCS=	00readme readme.meadow.j yatex.new yatexj.tex yatex.ref	\
		yahtmlj.tex htmlqa yatexadd.doc yatexgen.doc qanda
INFOFILES=	yatexj:yatexe:yahtmlj:yahtmle
INFONODES=	YaTeX-jp:YaTeX:yahtml-jp:yahtml
INFONODEEXPS=	Yet Another tex-mode for Emacs. (Japanese):Yet Another tex-mode for Emacs.:Yet Another HTML mode. (Japanese):Yet Another HTML mode.
.endif

PORTDOCS+=	yatexe.tex htmlqa.eng yahtmle.tex yatexref.eng qanda.eng
EL_FILES=	comment.el yatex.el yatexadd.el yatexgen.el \
		yatexenv.el yatexlib.el \
		yatexmth.el yatexhks.el yatexhlp.el yatexprc.el \
		yatexm-o.el yatexsec.el  yatexpkg.el yatexhie.el yahtml.el \
		yatex19.el

do-build:
	@${DO_NADA}
# For XEmacs, yatexj (a Japanese info file) should be remade.
.if (${EMACS_PORT_NAME} == xemacs21-mule)
	cd ${WRKSRC}/docs && \
	${SETENV} LANG=ja_JP.eucJP ${EMACS_CMD} -no-site-file -no-init-file \
		-batch -l texinfmt -f batch-texinfo-format yatexj.tex
.endif

do-install:
	${MKDIR} ${ELISPDIR}/yatex ${HELPDIR} ${INFODIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${EL_FILES} ${ELISPDIR}/yatex && \
		${INSTALL_DATA} ${HELP} ${HELPDIR}
.if (${EMACS_PORT_NAME} == xemacs21) || (${EMACS_PORT_NAME} == xemacs21-mule)
	for F in ${INFOFILES:S,:, ,g}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$${F} ${INFODIR}/$${F}.info; \
	done
.else
	cd ${WRKSRC}/docs && \
		${INSTALL_DATA} ${INFOFILES:S,:, ,g} ${INFODIR}
.endif
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/docs/* ${WRKSRC}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${SETENV} TOUCH=${TOUCH} INFODIR=${INFODIR} \
		ELISPDIR=${ELISPDIR} DIRSECTION="${DIRSECTION}" \
		INFOFILES="${INFOFILES}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_DATA} ${WRKDIR}/yatex-startup.el ${ELISPDIR}
.if (${EMACS_PORT_NAME} == xemacs21) || (${EMACS_PORT_NAME} == xemacs21-mule)
	${RM} -f ${WRKDIR}/${MANIFEST}
	${CAT} ${PLIST} | ${GREP} -e "^${EMACS_LIBDIR}" | \
		${SED} -e "s;^${EMACS_LIBDIR}/;;" > ${WRKDIR}/${MANIFEST}
	${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/site-packages/pkginfo
	${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${PREFIX}/${EMACS_LIBDIR}/site-packages/pkginfo/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
