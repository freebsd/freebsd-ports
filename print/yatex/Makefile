# New ports collection makefile for: YaTeX
# Date created:		98/11/17
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yatex
PORTVERSION=	${VERSION}
CATEGORIES?=	print elisp
MASTER_SITES=	http://www.yatex.org/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

.if defined(XEMACS-MULE)
BUILD_DEPENDS=	xemacs:${PORTSDIR}/japanese/xemacs21-canna \
		{LOCALBASE}/${EMACS_PACKAGESDIR}/../xemacs-packages/lisp/texinfo/texinfo.el:${PORTSDIR}/editors/xemacs-packages \
		nkf:${PORTSDIR}/japanese/nkf
.endif
PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL
PKGMESSAGE=	${WRKDIR}/MESSAGE
VERSION=	1.67
TARGETNAME=	YaTeX
DIRSECTION=	The Emacs editor and associated tools

# Note that 'INFODIR' is defined in bsd.info.mk
.if defined(XEMACS)
EMACS=		xemacs
EMACSDIR=	${PREFIX}/lib/xemacs/site-packages
INFODIR=	${EMACSDIR}/info
PLIST=		${PKGDIR}/PLIST.xemacs
MANIFEST=	MANIFEST.yatex
.elif defined(XEMACS-MULE)
EMACS=		xemacs
EMACSDIR=	${PREFIX}/lib/xemacs/site-packages
INFODIR=	${EMACSDIR}/info
PLIST=		${PKGDIR}/PLIST.xemacs-mule
MANIFEST=	MANIFEST.yatex
.elif defined(MULE)
EMACS=		mule
EMACSDIR=	${PREFIX}/share/mule
INFODIR=	${PREFIX}/info
PLIST=		${PKGDIR}/PLIST.mule
.else
EMACS=		emacs
EMACSDIR=	${PREFIX}/share/emacs
INFODIR=	${PREFIX}/info
PLIST=		${PKGDIR}/PLIST.emacs
.endif
.if defined(XEMACS)
NEW=
HELP=		help/YATEXHLP.eng
INFOFILES=	yatexe
INFONODES=	YaTeX
INFONODEEXPS=	Yet Another tex-mode for Emacs.
.else
NEW=		yatex.new
HELP=		help/YATEXHLP.jp help/YATEXHLP.eng
DOCSRC=		docs/yatexj.tex \
		docs/yatex.ref \
		docs/yahtmlj.tex docs/htmlqa \
		docs/yatexadd.doc docs/yatexgen.doc \
		docs/qanda
INFOFILES=	yatexj:yatexe:yahtmlj
INFONODES=	YaTeX-jp:YaTeX:yahtml-jp
INFONODEEXPS=	Yet Another tex-mode for Emacs. (Japanese):Yet Another tex-mode for Emacs.:Yet Another HTML mode. (Japanese)
.endif
DOCSRC+=	docs/yatexe.tex \
		docs/yatexref.eng \
		docs/qanda.eng
.if defined(XEMACS) || defined(XEMACS-MULE)
ELISPDIR=	${EMACSDIR}/lisp
HELPDIR=	${EMACSDIR}/../site-lisp
.else
ELISPDIR=	${EMACSDIR}/site-lisp
HELPDIR=	${ELISPDIR}
.endif
PORTSDOCDIR=	${PREFIX}/share/doc/yatex
EL_FILES=	comment.el yatex.el yatexadd.el yatexgen.el \
		yatexenv.el yatexlib.el \
		yatexmth.el yatexhks.el yatexhlp.el yatexprc.el \
		yatexm-o.el yatexsec.el  yatexhie.el yahtml.el \
		yatex19.el

do-build:
	for file in yatex-startup.el INSTALL DEINSTALL MESSAGE; do \
	  ${SED} -e 's,%%TARGETNAME%%,${TARGETNAME},g' \
		 -e 's,%%VERSION%%,${VERSION},g' \
		 -e 's,%%PREFIX%%,${PREFIX},g' \
		 -e 's,%%BASENAME%%,${BASENAME},g' \
		 -e 's,%%CAT%%,${CAT},g' \
		 -e 's,%%CP%%,${CP},g' \
		 -e 's,%%ECHO%%,${ECHO},g' \
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
		 -e 's,%%EMACS%%,${EMACS},g' \
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
.if defined(XEMACS) || defined(XEMACS-MULE)
	cd ${WRKSRC}; \
	for file in `${ECHO} ${INFOFILES} | ${SED} "s,:, ,g"`; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$${file} ${INFODIR}/$${file}.info; \
	done
.else
	cd ${WRKSRC}; \
	for file in `${ECHO} ${INFOFILES} | ${SED} "s,:, ,g"`; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$${file} ${INFODIR}; \
	done
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTSDOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${NEW} ${DOCSRC} ${PORTSDOCDIR}
.endif

post-install:
	@${SETENV} TOUCH=${TOUCH} INFODIR=${INFODIR} \
		ELISPDIR=${ELISPDIR} DIRSECTION="${DIRSECTION}" \
		INFOFILES="${INFOFILES}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_DATA} ${WRKDIR}/yatex-startup.el ${ELISPDIR}
	@${CAT} ${PKGMESSAGE}
.if defined(XEMACS) || defined(XEMACS-MULE)
	${RM} -f ${WRKDIR}/${MANIFEST}
	emacsdir=`${ECHO} ${EMACSDIR} | ${SED} -e "s;^${PREFIX}/;;"`; \
	${CAT} ${PLIST} | ${GREP} -e "^$${emacsdir}" | \
		${SED} -e "s;^$${emacsdir}/;;" > ${WRKDIR}/${MANIFEST}
	${MKDIR} ${EMACSDIR}/pkginfo
	${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${EMACSDIR}/pkginfo/
.endif

.include <bsd.port.mk>
