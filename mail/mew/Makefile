# New ports collection makefile for: Mew
# Version required:	1.70
# Date created:		30 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.3 1997/01/03 16:52:53 max Exp $
#

PKGNAME=	mew-1.70
CATEGORIES=	mail
FILESDIR=	${.CURDIR}/../../japanese/mew/files
PATCHDIR=	${.CURDIR}/../../japanese/mew/patches

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs \
		mhmail:${PORTSDIR}/mail/mh

EMACSCMD=	emacs
EMACSEL=	mew-mule0.el
PORTSDOCDIR=	${PREFIX}/share/doc/mew
SAMPLEDIR=	${PREFIX}/share/examples/mew
ELISPDIR=	${PREFIX}/share/emacs/site-lisp
INFOFILE=	mew.info
MHPOSTPROC=	MH-postproc
SCANFORM=	scan.form
DOTEMACS=	dot.emacs
DOTMHPROFILE=	dot.mh_profile

.include "${.CURDIR}/../../japanese/mew/Makefile"
