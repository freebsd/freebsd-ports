# New ports collection makefile for: Mew (for mule)
# Version required:	1.92.4
# Date created:		21 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id$
#

PKGNAME?=	mew-mule-1.92.4

EMACSCMD=	mule
ELISPDIR=	${PREFIX}/lib/mule/site-lisp
WRKDIR=		${.CURDIR}/../../mail/mew-mule/work
INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}

.if defined(ZH_MULE)
DIRENTRY=	"* Mew-ch: (mew).	Messaging in the Emacs World (Chinese)."
INFOFILE=	mew.info
.endif
.if defined(JA_MULE)
DIRENTRY=	"* Mew-ja: (mew.jis).	Messaging in the Emacs World (Japanese)."
INFOFILE=	mew.jis.info
.endif
.if defined(KO_MULE)
DIRENTRY=	"* Mew-ko: (mew).	Messaging in the Emacs World (Korean)."
INFOFILE=	mew.info
.endif
.if defined(RU_MULE)
DIRENTRY=	"* Mew-ru: (mew).	Messaging in the Emacs World (Russian)."
INFOFILE=	mew.info
.endif
.if defined(VI_MULE)
DIRENTRY=	"* Mew-vi: (mew).	Messaging in the Emacs World (Vietnamese)."
INFOFILE=	mew.info
.endif

.if defined(ZH_MULE) || defined(JA_MULE) || defined(KO_MULE) || \
    defined(RU_MULE) || defined(VI_MULE)
I18N=		yes
I18N_PHASE=	"I18N=${I18N}"
MEW_RUN_REQ=	${PREFIX}/bin/mewcat:${PORTSDIR}/mail/mew-mule

pre-install:
	@${TOUCH} ${TOUCH_FLAGS} ${PLIST}
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
	@(cd ${FILESDIR}; \
	${CP} INSTALL DEINSTALL ${PKGDIR}; \
	${RM} -f ${FILESDIR}/${TMPL_FILES}; \
	)
.else
MULE=		yes
BUILD_DEPENDS=	mule:${PORTSDIR}/editors/mule
MEW_RUN_REQ=	${PREFIX}/lib/mule/site-lisp:${PORTSDIR}/editors/mule-common \
		${PREFIX}/bin/mewcat:${PORTSDIR}/mail/mew-common
.endif

.include "${.CURDIR}/../../mail/mew-common/Makefile"
