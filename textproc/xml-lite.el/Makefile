# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	xml-lite.el
PORTVERSION=	1.1
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	http://dogbiscuit.org/mdub/software/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple XML-editing for GNU Emacs

USE_EMACS=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=${WRKSRC}/${PORTNAME}

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME} \
		${EMACS_SITE_LISPDIR}/${PORTNAME}c

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile ${PORTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}c \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
