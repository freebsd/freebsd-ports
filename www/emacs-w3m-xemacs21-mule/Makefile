# New ports collection makefile for:	emacs-w3m-xemacs21-mule
# Date Created:		11 Apr 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../emacs-w3m

EMACS_PORT_NAME=	xemacs21-mule
COMMENT=	Simple front-end to w3m for xemacs21-mule

CONFIGURE_ARGS=		--with-xemacs=${EMACS_CMD} \
			--with-packagedir=${PREFIX}/${EMACS_PACKAGESDIR}
EMACS_PACKAGESDIR=	lib/xemacs/site-packages
LISPDIR=		${EMACS_PACKAGESDIR}/lisp/w3m
ICONDIR=		${EMACS_PACKAGESDIR}/etc/images/w3m
INFODIR=		${EMACS_PACKAGESDIR}/info
PKGINFODIR=		${EMACS_PACKAGESDIR}/pkginfo
INSTALL_TARGET=		install-package

PLIST=			${.CURDIR}/pkg-plist
PLIST_SUB+=		PKGINFODIR=${PKGINFODIR} EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}

WITHOUT_OCTET_VIEWER=	yes

.include "${MASTERDIR}/Makefile"
