# New ports collection makefile for:	tramp (for emacs21)
# Date Created:		12 Dec 2001
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tramp
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	net elisp
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparent remote file access tool for emacsen

EMACS_PORT_NAME?=	emacs21

USE_GMAKE=	yes
USE_AUTOCONF_VER=	259

TRAMP_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
PLIST_SUB+=	TRAMP_LISPDIR=${TRAMP_LISPDIR} \
		DIRSECTION=${DIRSECTION} \
		INFOENTRY=${INFOENTRY} INFOENTRY_JA=${INFOENTRY_JA}
CONFIGURE_ENV=	TEXI2DVI=no
CONFIGURE_ARGS=	--with-contrib --prefix=${PREFIX} \
		--with-lispdir=${PREFIX}/${TRAMP_LISPDIR} \
		--with-emacs=${EMACS_CMD}

.if defined(JAPANESE_INFO)
CONFIGURE_ARGS+=	--with-japanese-manual
PLIST_SUB+=	JAPANESE_INFO=""
.else
PLIST_SUB+=	JAPANESE_INFO="@comment "
.endif

.if ${EMACS_PORT_NAME} == emacs20
PLIST_SUB+=	EMACS20_ONLY=""
.else
PLIST_SUB+=	EMACS20_ONLY="@comment "
.endif

pre-build:
.if ${EMACS_PORT_NAME} == emacs20
	(cd ${WRKSRC}/contrib; ${GMAKE})
.endif
	${LN} -sf ../contrib/password.el ${WRKSRC}/lisp

post-install:
.if ${EMACS_PORT_NAME} == emacs20
	(cd ${WRKSRC}/contrib; ${GMAKE} install)
.endif

.include <bsd.port.mk>
