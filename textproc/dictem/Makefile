# New ports collection makefile for:	dictem
# Date created:				24 Apr 2006
# Whom:					Max N. Boyarov <m.boyarov@gmail.com>
#
# $FreeBSD$

PORTNAME=	dictem
PORTVERSION=	0.7
CATEGORIES=	textproc net elisp
MASTER_SITES=	http://www.mova.org/~cheusov/pub/dictem/ \
		http://ncd0.bsd.by/ports/distfiles/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	m.boyarov@gmail.com
COMMENT=	DictEm is a dict client for [X]Emacs

USE_EMACS=	yes
USE_AUTOTOOLS=	autoconf:259

EMACS_PORT_NAME?=emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=		EMACS=${EMACS_CMD} EMACSLOADPATH=${EMACS_BASE}/${EMACS_CORE_DIR}
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_BASE}/${LISPDIR}

PLIST_FILES+=	${LISPDIR}/dictem.el	\
		${LISPDIR}/dictem.elc
PLIST_DIRS+=	${LISPDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS+=	README AUTHORS NEWS ChangeLog COPYING

.include <bsd.port.pre.mk>

.if ${EMACS_NAME} == "xemacs"
LISPDIR=	${EMACS_LIBDIR}/site-packages/lisp/dictem
.else
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/dictem
.endif

pre-configure:
	${INSTALL_SCRIPT} ${AUTOCONF_DIR}/missing ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
