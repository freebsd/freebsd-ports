# New ports collection makefile for:   rst.el
# Date created:                Sun Aug 20 18:39:03 MSD 2006
# Whom:                        Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	rst.el
PORTVERSION=	5648
PORTREVISION=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	http://svn.berlios.de/viewcvs/*checkout*/docutils/trunk/docutils/tools/editors/emacs/
PKGNAMESUFFIX=	-${EMACS_NAME}
DISTNAME=	rst.el\?rev=${PORTVERSION}
EXTRACT_SUFX=	# empty

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	ReStructuredText Support for Emacs

USE_EMACS=	yes
EMACS_PORT_NAME?=	xemacs21-mule

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}/rst.el

ELISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.pre.mk>

.if (${EMACS_NAME} == "xemacs")
BUILD_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/lisp/xemacs-base/compile.el:${PORTSDIR}/editors/xemacs-packages
.endif

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile ${PORTNAME}

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}c ${ELISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
