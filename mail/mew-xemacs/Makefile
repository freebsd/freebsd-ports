# New ports collection makefile for: Mew (for xemacs)
# Version required:	1.92.4
# Date created:		17 January 1998
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id$
#

PKGNAME?=	mew-xemacs-1.92.4

LANGUAGE?=
XEMACS=		yes
DIRENTRY=	"* Mew::		Messaging in the Emacs World (English)."
INFOFILE=	mew.info

.if (${LANGUAGE} == "Chinese")
.endif
.if (${LANGUAGE} == "Japanese")
DIRENTRY+=	"* Mew.jis::	Messaging in the Emacs World (Japanese)."
INFOFILE+=	mew.jis.info
.endif
.if (${LANGUAGE} == "Korean")
.endif
.if (${LANGUAGE} == "Russian")
.endif
.if (${LANGUAGE} == "Vietnamese")
.endif

post-install::
.for f in mew.info mew.info-1 mew.info-2 mew.info-3
	@ln -sf ${PREFIX}/info/${f} ${INFODIR}/${f}
.endfor

.include "${.CURDIR}/../../mail/mew-common/Makefile"
