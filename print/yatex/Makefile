# New ports collection makefile for: YaTeX
# Date created:		98/11/17
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yatex
PORTVERSION=	1.72
CATEGORIES?=	print elisp
MASTER_SITES=	http://www.yatex.org/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	Yet Another LaTeX mode and html mode on Emacs (for Emacs{19,20} and XEmacs{19,20})

PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL
PKGMESSAGE=	${WRKDIR}/MESSAGE
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

EMACS_PORT_NAME?=emacs21
EMACS_NO_RUN_DEPENDS=YES
.if (${EMACS_PORT_NAME} != xemacs21-mule)
EMACS_NO_BUILD_DEPENDS=YES
.endif

VERSION=	${PORTVERSION}
TARGETNAME=	YaTeX
DIRSECTION=	The Emacs editor and associated tools
EMACS_PACKAGESDIR=${EMACS_LIBDIR}/site-packages
# Note that 'INFODIR' is defined in bsd.info.mk
.if (${EMACS_PORT_NAME} == xemacs21)
INFODIR=	${PREFIX}/${EMACS_PACKAGESDIR}/info
ELISPDIR=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp
HELPDIR=	${PREFIX}/${EMACS_LIBDIR}/site-lisp
PLIST=		${PKGDIR}/pkg-plist.xemacs
MANIFEST=	MANIFEST.yatex
.elif (${EMACS_PORT_NAME} == xemacs21-mule)
INFODIR=	${PREFIX}/${EMACS_PACKAGESDIR}/info
ELISPDIR=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp
HELPDIR=	${PREFIX}/${EMACS_LIBDIR}/site-lisp
PLIST=		${PKGDIR}/pkg-plist.xemacs-mule
MANIFEST=	MANIFEST.yatex
.elif (${EMACS_PORT_NAME} == mule)
INFODIR=	${PREFIX}/info
PLIST=		${PKGDIR}/pkg-plist.mule
ELISPDIR=	${PREFIX}/${EMACS_LIBDIR}/site-lisp
HELPDIR=	${ELISPDIR}
.else
INFODIR=	${PREFIX}/info
PLIST=		${PKGDIR}/pkg-plist.emacs
ELISPDIR=	${PREFIX}/${EMACS_LIBDIR}/site-lisp
HELPDIR=	${ELISPDIR}
.endif
PORTSDOCDIR=	${PREFIX}/share/doc/yatex
.if (${EMACS_PORT_NAME} == xemacs21)
DOCS=
HELP=		help/YATEXHLP.eng
INFOFILES=	yatexe:yahtmle
INFONODES=	YaTeX:yahtml
INFONODEEXPS=	Yet Another tex-mode for Emacs.:Yet Another HTML mode.
.else
DOCS=		00readme readme.meadow.j yatex.new
HELP=		help/YATEXHLP.jp help/YATEXHLP.eng
DOCSRC=		docs/yatexj.tex \
		docs/yatex.ref \
		docs/yahtmlj.tex docs/htmlqa \
		docs/yatexadd.doc docs/yatexgen.doc \
		docs/qanda
INFOFILES=	yatexj:yatexe:yahtmlj:yahtmle
INFONODES=	YaTeX-jp:YaTeX:yahtml-jp:yahtml
INFONODEEXPS=	Yet Another tex-mode for Emacs. (Japanese):Yet Another tex-mode for Emacs.:Yet Another HTML mode. (Japanese):Yet Another HTML mode.
.endif
DOCSRC+=	docs/yatexe.tex \
		docs/htmlqa.eng docs/yahtmle.tex \
		docs/yatexref.eng \
		docs/qanda.eng
EL_FILES=	comment.el yatex.el yatexadd.el yatexgen.el \
		yatexenv.el yatexlib.el \
		yatexmth.el yatexhks.el yatexhlp.el yatexprc.el \
		yatexm-o.el yatexsec.el  yatexpkg.el yatexhie.el yahtml.el \
		yatex19.el

do-build:
	for file in yatex-startup.el INSTALL DEINSTALL MESSAGE; do \
	  ${SED} -e 's,%%TARGETNAME%%,${TARGETNAME},g' \
		 -e 's,%%VERSION%%,${VERSION},g' \
		 -e 's,%%PREFIX%%,${PREFIX},g' \
		 -e 's,%%BASENAME%%,${BASENAME},g' \
		 -e 's,%%CAT%%,${CAT},g' \
		 -e 's,%%CP%%,${CP},g' \
		 -e 's,%%ECHO%%,${ECHO_CMD},g' \
		 -e 's,%%GREP%%,${GREP},g' \
		 -e 's,%%RM%%,${RM},g' \
		 -e 's,%%SED%%,${SED},g' \
		 -e 's,%%TOUCH%%,${TOUCH},g' \
		 -e 's,%%DO_NADA%%,${DO_NADA},g' \
		 -e 's,%%INFODIR%%,${INFODIR},g' \
		 -e 's,%%ELISPDIR%%,${ELISPDIR},g' \
		 -e 's,%%INFOFILES%%,${INFOFILES},g' \
		 -e 's,%%INFONODES%%,${INFONODES},g' \
		 -e 's,%%INFONODEEXPS%%,${INFONODEEXPS},g' \
		 -e 's,%%DIRSECTION%%,${DIRSECTION},g' \
		 -e 's,%%EMACS_NAME%%,${EMACS_NAME},g' \
		< ${FILESDIR}/$${file}.tmpl > ${WRKDIR}/$${file}; \
	done
# For XEmacs, yatexj (a Japanese info file) should be remade.
.if (${EMACS_PORT_NAME} == xemacs21-mule)
	(cd ${WRKSRC}/docs; \
	${SETENV} LANG=ja_JP.eucJP ${EMACS_CMD} -no-site-file -no-init-file \
		-batch -l texinfmt -f batch-texinfo-format yatexj.tex; \
	)
.endif

do-install:
	cd ${WRKSRC}; \
	${MKDIR} ${ELISPDIR}/yatex; \
	${MKDIR} ${HELPDIR} ${INFODIR}; \
	${INSTALL_DATA} ${EL_FILES} ${ELISPDIR}/yatex; \
	${INSTALL_DATA} ${HELP} ${HELPDIR}; \
	${MKDIR} ${INFODIR}
.if (${EMACS_PORT_NAME} == xemacs21) || (${EMACS_PORT_NAME} == xemacs21-mule)
	cd ${WRKSRC}; \
	for file in `${ECHO_CMD} ${INFOFILES} | ${SED} "s,:, ,g"`; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$${file} ${INFODIR}/$${file}.info; \
	done
.else
	cd ${WRKSRC}; \
	for file in `${ECHO_CMD} ${INFOFILES} | ${SED} "s,:, ,g"`; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$${file} ${INFODIR}; \
	done
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTSDOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCS} ${DOCSRC} ${PORTSDOCDIR}
.endif

post-install:
	@${SETENV} TOUCH=${TOUCH} INFODIR=${INFODIR} \
		ELISPDIR=${ELISPDIR} DIRSECTION="${DIRSECTION}" \
		INFOFILES="${INFOFILES}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_DATA} ${WRKDIR}/yatex-startup.el ${ELISPDIR}
	@${CAT} ${PKGMESSAGE}
.if (${EMACS_PORT_NAME} == xemacs21) || (${EMACS_PORT_NAME} == xemacs21-mule)
	${RM} -f ${WRKDIR}/${MANIFEST}
	${CAT} ${PLIST} | ${GREP} -e "^${EMACS_LIBDIR}" | \
		${SED} -e "s;^${EMACS_LIBDIR}/;;" > ${WRKDIR}/${MANIFEST}
	${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/site-packages/pkginfo
	${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${PREFIX}/${EMACS_LIBDIR}/site-packages/pkginfo/
.endif

.include <bsd.port.mk>
