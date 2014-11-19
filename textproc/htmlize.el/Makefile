# Created by: Marc van Woerkom <marc.vanwoerkom@fernuni-hagen.de>
# $FreeBSD$

PORTNAME=	htmlize.el
PORTVERSION=	1.39
PORTREVISION=	2
CATEGORIES=	textproc elisp
MASTER_SITES=	http://fly.srk.fer.hr/~hniksic/emacs/
DISTNAME=	${PORTNAME}.cgi
EXTRACT_SUFX=
DIST_SUBDIR=	repacked

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Emacs major mode to create HTML files from Emacs buffers (in colour!)

USE_EMACS=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}/htmlize.el

PLIST_FILES=	${EMACS_SITE_LISPDIR}/htmlize.el \
		${EMACS_SITE_LISPDIR}/htmlize.elc

LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile htmlize.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/htmlize.* ${STAGEDIR}${LISPDIR}

.include <bsd.port.mk>
