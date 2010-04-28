# New ports collection makefile for:   xml-lite.el
# Date created:                18 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	xml-lite.el
PORTVERSION=	1.1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	http://dogbiscuit.org/mdub/software/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple XML-editing for GNU Emacs

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=${WRKSRC}/${PORTNAME}

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME} \
		${EMACS_SITE_LISPDIR}/${PORTNAME}c

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile ${PORTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}c ${PREFIX}/${EMACS_SITE_LISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
