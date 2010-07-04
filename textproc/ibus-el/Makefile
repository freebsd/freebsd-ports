# New ports collection makefile for:   ibus-el
# Date created:        4 July 2010
# Whom:                Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-el
PORTVERSION=	0.1.1
#PORTREVISION=	0
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www11.atwiki.jp/s-irie/pub/emacs/ibus/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	IBus client for GNU Emacs

RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus \
		${PYTHON_SITELIBDIR}/Xlib/X.py:${PORTSDIR}/x11-toolkits/py-xlib

USE_EMACS=	yes
USE_PYTHON_RUN=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/doc/COPYING

PLIST_DIRS=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME} share/${PORTNAME}
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}/ibus.el \
		${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}/ibus.elc \
		share/${PORTNAME}/ibus-el-agent
PORTDOCS=	README

do-build:
	@cd ${WRKSRC} && ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile ibus.el

do-install:
	@${MKDIR} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/ibus.el \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/ibus.elc \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/ibus-el-agent ${PREFIX}/share/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
