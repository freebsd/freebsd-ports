# New ports collection makefile for: w3 on Emacs
# Date created:		31 December 1996
# Whom:			MITA Yoshio <mita@ee.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	w3-${EMACS_PORT_NAME}
PORTVERSION=	4.0.p47
PORTREVISION=	2
CATEGORIES+=	www elisp
MASTER_SITES=	${MASTER_SITE_XEMACS}
MASTER_SITE_SUBDIR=	emacs-w3
DISTNAME=	w3-4.0pre.47

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WWW browser based on emacs/mule

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=yes
INSTALL_TARGET=	install

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

INFO=		w3-faq w3

.include <bsd.port.pre.mk>

PLIST_SUB+=	EMACS_VERSION_SITE_LISPDIR=${EMACS_VERSION_SITE_LISPDIR}

.if (${EMACS_NAME} == "xemacs")
CONFIGURE_ARGS=	--with-xemacs=${EMACS_NAME}
.else
CONFIGURE_ARGS=	--with-emacs=${EMACS_NAME}
.endif
CONFIGURE_ARGS+=	--enable-site-install \
			--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/w3
CONFIGURE_ENV+=	MAKEINFO='makeinfo --no-split'

.include <bsd.port.post.mk>
