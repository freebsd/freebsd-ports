# New ports collection makefile for:        latte
# Date created:         15 August 1999
# Whom:                 Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	latte
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.latte.org/ \
		ftp://ftp.brasslantern.com/pub/zanshin/latte/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple language for marking up text in a very expressive way

USE_LIBTOOL_VER=13
MAKE_FLAGS=	CONF_ARGS="--prefix=${PREFIX}"
CONFIGURE_ARGS+=	--enable-shared

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502102
BROKEN=		"Configure fails"
.endif

post-install:
	${LN} -sf ${PREFIX}/bin/latte-html ${PREFIX}/bin/latte
	${CP} -Rp ${WRKSRC}/tests ${PREFIX}/share/latte/
	${INSTALL_DATA} ${WRKSRC}/latte.el ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.post.mk>
