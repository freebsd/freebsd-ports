# New ports collection makefile for: YaTeX
# Version required:	1.66
# Date created:		98/11/17
# Whom:			Satoshi Taoka <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.6 1998/12/01 03:06:39 asami Exp $
#

DISTNAME=	yatex1.66
PKGNAME?=	yatex-1.66
CATEGORIES?=	print elisp
MASTER_SITES=	http://www.comp.ae.keio.ac.jp/~yuuji/yatex/ \
		http://www.comp.ae.keio.ac.jp/~yuuji/tmp/

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

WRKSRC=		${WRKDIR}/yatex${VERSION}
.if defined(XEMACS-MULE)
BUILD_DEPENDS=	xemacs:${PORTSDIR}/editors/xemacs-mule \
		nkf:${PORTSDIR}/japanese/nkf \
		bash:${PORTSDIR}/shells/bash2
.endif

PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL
VERSION=	1.66
TARGETNAME=	YaTeX
DIRSECTION=	The Emacs editor and associated tools
ADDSITESTART=
SITESTARTDIR=
# Note that 'INFODIR' is defined in bsd.info.mk
.if !defined(XEMACS-MULE)
INFODIR=	${PREFIX}/info
.endif
.if defined(MULE)
# The value of ADDSITESTART should follow a format of printf(1)
ADDSITESTART=	(setq load-path (append (list \\n\
		\\t\\"${ELISPDIR}/yatex\\"\\n\
		\\t) load-path))\\n
EMACSDIR=	${PREFIX}/share/mule
SITESTARTDIR=	${EMACSDIR}/19.34/site-lisp
.endif
.if defined(XEMACS-MULE)
EMACS=		xemacs
EMACSDIR=	${PREFIX}/lib/xemacs
#
INFODIR=	${EMACSDIR}/info
.endif
.if defined(MULE) || defined(XEMACS-MULE)
NEW=		yatex.new
HELP=		help/YATEXHLP.jp help/YATEXHLP.eng
DOCSRC=		docs/yatexj.tex \
		docs/yatex.ref \
		docs/yatexadd.doc docs/yatexgen.doc \
		docs/qanda
INFOFILES=	yatexj:yatexe
INFONODES=	YaTeX-jp:YaTeX
INFONODEEXPS=	Yet Another tex-mode for Emacs. (Japanese):Yet Another tex-mode for Emacs.
.endif
.if !defined(MULE) && !defined(XEMACS-MULE)
EMACSDIR=	${PREFIX}/share/emacs
NEW=
HELP=		help/YATEXHLP.eng
INFOFILES=	yatexe
INFONODES=	YaTeX
INFONODEEXPS=	Yet Another tex-mode for Emacs.
.endif
DOCSRC+=	docs/yatexe.tex \
		docs/yatexref.eng \
		docs/qanda.eng
ELISPDIR=	${EMACSDIR}/site-lisp
PORTSDOCDIR=	${PREFIX}/share/doc/yatex
EL_FILES=	comment.el yatex.el yatexadd.el yatexgen.el \
		yatexenv.el yatexlib.el \
		yatexmth.el yatexhks.el yatexhlp.el yatexprc.el \
		yatexm-o.el yatexsec.el  yatexhie.el yahtml.el \
		yatex19.el

do-build:
	for file in user-install INSTALL DEINSTALL; do \
	  ${SED} -e 's,%TARGETNAME%,${TARGETNAME},g' \
		 -e 's,%VERSION%,${VERSION},g' \
		 -e 's,%PREFIX%,${PREFIX},g' \
		 -e 's,%BASENAME%,${BASENAME},g' \
		 -e 's,%CAT%,${CAT},g' \
		 -e 's,%CP%,${CP},g' \
		 -e 's,%ECHO%,${ECHO},g' \
		 -e 's,%GREP%,${GREP},g' \
		 -e 's,%RM%,${RM},g' \
		 -e 's,%SED%,${SED},g' \
		 -e 's,%TOUCH%,${TOUCH},g' \
		 -e 's,%DO_NADA%,${DO_NADA},g' \
		 -e 's,%INFODIR%,${INFODIR},g' \
		 -e 's,%ELISPDIR%,${ELISPDIR},g' \
		 -e 's,%INFOFILES%,${INFOFILES},g' \
		 -e 's,%INFONODES%,${INFONODES},g' \
		 -e 's,%INFONODEEXPS%,${INFONODEEXPS},g' \
		 -e 's,%DIRSECTION%,${DIRSECTION},g' \
		 -e 's,%SITESTARTDIR%,${SITESTARTDIR},g' \
		 -e 's,%ADDSITESTART%,${ADDSITESTART},g' \
		< ${FILESDIR}/$${file}.tmpl > ${WRKDIR}/$${file}; \
	done
# For XEmacs-mule 20.4, yatexj.info (in Japanese) should be remade
# after Kanji code of yatexj.tex is convert from shift jis (MS-Kanji)
# to EUC.
.if defined(XEMACS-MULE)
	(cd ${WRKSRC}/docs; \
	${MV} yatexj.tex yatexj.tex.org; \
	nkf -e yatexj.tex.org > yatexj.tex; \
	${SETENV} LANG=ja_JP.EUC ${EMACS} -no-site-file -no-init-file \
		-batch yatexj.tex -e texinfo-format-buffer -f save-buffer; \
	)
.endif

do-install:
	(cd ${WRKSRC}; \
	${MKDIR} ${ELISPDIR}/yatex; \
	${INSTALL_DATA} ${EL_FILES} ${ELISPDIR}/yatex; \
	${INSTALL_DATA} ${HELP} ${ELISPDIR}; \
	${MKDIR} ${INFODIR}; \
	for file in `${ECHO} ${INFOFILES} | ${SED} "s,:, ,g"`; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$${file} ${INFODIR}; \
	done; \
	)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTSDOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${NEW} ${DOCSRC} ${PORTSDOCDIR}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL_SCRIPT} ${WRKDIR}/user-install ${PORTSDOCDIR}
.endif
	if [ ! -f ${INFODIR}/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${INFODIR}/dir; \
	fi
	@${SETENV} TOUCH=${TOUCH} INFODIR=${INFODIR} \
		ELISPDIR=${ELISPDIR} DIRSECTION="${DIRSECTION}" \
		INFOFILES="${INFOFILES}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
