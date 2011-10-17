# New ports collection makefile for:	xcite
# Date created:		8 Novemver 2008
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcite
PORTVERSION=	1.60
#PORTREVISION=	0
PORTREVISION=	3
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.gentei.org/~yuuji/software/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}.el
EXTRACT_SUFX=	# empty

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Exciting Cite for any Mail/News reading modes on Emacs

USE_EMACS=	yes

NO_WRKSUBDIR=	yes

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	.

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/${DISTNAME} \
		${EMACS_VERSION_SITE_LISPDIR}/${DISTNAME}c

do-build:
	@cd ${WRKDIR} && ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile ${DISTNAME}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME} \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}c \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
