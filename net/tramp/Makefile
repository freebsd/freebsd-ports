# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tramp
PORTVERSION=	2.3.0
#PORTREVISION=	0
CATEGORIES=	net elisp
MASTER_SITES=	GNU
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Transparent remote file access tool for emacsen

USE_EMACS=	yes

USES=		cpe gmake makeinfo
USE_AUTOTOOLS=	autoconf
CPE_VENDOR=	gnu

TRAMP_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
PLIST_SUB+=	TRAMP_LISPDIR=${TRAMP_LISPDIR}
CONFIGURE_ENV=	TEXI2DVI=no
CONFIGURE_ARGS=	--with-contrib --prefix=${PREFIX} \
		--with-lispdir=${PREFIX}/${TRAMP_LISPDIR} \
		--with-emacs=${EMACS_CMD}

INFO=		tramp21

.if defined(JAPANESE_INFO)
CONFIGURE_ARGS+=	--with-japanese-manual
INFO+=		tramp
.endif

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} == emacs20
PLIST_SUB+=	EMACS20_ONLY=""
.else
PLIST_SUB+=	EMACS20_ONLY="@comment "
.endif

pre-build:
.if ${EMACS_PORT_NAME} == emacs20
	(cd ${WRKSRC}/contrib; ${MAKE_CMD})
.endif
	${LN} -sf ../contrib/password.el ${WRKSRC}/lisp

post-install:
.if ${EMACS_PORT_NAME} == emacs20
	(cd ${WRKSRC}/contrib; ${MAKE_CMD} install)
.endif

.include <bsd.port.post.mk>
