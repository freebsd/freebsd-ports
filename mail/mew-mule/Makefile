# New ports collection makefile for: Mew (for mule)
# Version required:	1.92.4
# Date created:		21 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1997/12/08 22:08:36 max Exp $
#

PKGNAME?=	mew-mule-1.92.4

LANGUAGE?=
MULE=		yes
DIRENTRY=	"* Mew: (mew):	Messaging in the Emacs World (English)."
INFOFILE=	mew.info

.if (${LANGUAGE} == "Chinese")
.endif
.if (${LANGUAGE} == "Japanese")
DIRENTRY+=	"* Mew.jis: (mew.jis):	Messaging in the Emacs World (Japanese)."
INFOFILE+=	mew.jis.info
.endif
.if (${LANGUAGE} == "Korean")
.endif
.if (${LANGUAGE} == "Russian")
.endif
.if (${LANGUAGE} == "Vietnamese")
.endif

.include "${.CURDIR}/../../mail/mew-common/Makefile"
