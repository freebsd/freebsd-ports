# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../emacs-w3m

USE_EMACS=	yes
EMACS_PORT_NAME=	xemacs21-mule
COMMENT=	Simple front-end to w3m for xemacs21-mule

BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/texinfo/texinfmt.el:${PORTSDIR}/editors/xemacs-packages

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aclocal.m4
CONFIGURE_ARGS=		--with-xemacs=${EMACS_CMD} \
			--with-packagedir=${PREFIX}/${EMACS_PACKAGESDIR}
EMACS_PACKAGESDIR=	lib/xemacs/site-packages
LISPDIR=		${EMACS_PACKAGESDIR}/lisp/w3m
ICONDIR=		${EMACS_PACKAGESDIR}/etc/images/w3m
INFODIR=		${EMACS_PACKAGESDIR}/info
PKGINFODIR=		${EMACS_PACKAGESDIR}/pkginfo
INSTALL_TARGET=		install-package

INFO_PATH=		${INFODIR}

PLIST=			${.CURDIR}/pkg-plist
PLIST_SUB+=		PKGINFODIR=${PKGINFODIR} EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}

WITHOUT_OCTET_VIEWER=	yes

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
