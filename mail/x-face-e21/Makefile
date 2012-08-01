# New ports collection makefile for:	x-face-e21
# Date created:		10 September 2009
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x-face-e21
PORTVERSION=	20070306
PORTREVISION=	9
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.jpl.org/elips/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}.el
EXTRACT_SUFX=	.gz

MAINTAINER=	ume@FreeBSD.org
COMMENT=	X-Face utilities for Emacs 21 (and possibly 22)

RUN_DEPENDS=	uncompface:${PORTSDIR}/mail/faces
USE_EMACS=	yes

.include <bsd.port.pre.mk>

NO_WRKSUBDIR=	yes
EXTRACT_AFTER_ARGS=	> ${DISTNAME}

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

.include <bsd.port.post.mk>
