# New ports collection makefile for:	emacs-w3m-xemacs21-mule
# Date Created:		11 Apr 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../emacs-w3m

PORTCLASS=	slave

EMACS_PORT_NAME=	xemacs21-mule

CONFIGURE_ARGS=		--with-xemacs=${EMACS_CMD} \
			--with-packagedir=${PREFIX}/${EMACS_PACKAGESDIR}
EMACS_PACKAGESDIR=	lib/xemacs/site-packages
LISPDIR=		${EMACS_PACKAGESDIR}/lisp/w3m
ICONDIR=		${EMACS_PACKAGESDIR}/etc/w3m
PKGINFODIR=		${EMACS_PACKAGESDIR}/pkginfo
INSTALL_TARGET=		install-package

WITHOUT_OCTET_VIEWER=	yes

.include <${MASTERDIR}/Makefile>
