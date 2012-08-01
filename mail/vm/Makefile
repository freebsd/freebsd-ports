# New ports collection makefile for: vm
# Date created: 	20 February 2002
# Whom:			olive
#
# $FreeBSD$
#

PORTNAME=	vm
PORTVERSION=	8.1.2
PORTREVISION=	2
CATEGORIES=	mail elisp
MASTER_SITES=	https://launchpad.net/${PORTNAME}/8.1.x/${PORTVERSION}/+download/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhein@symmetricom.com
COMMENT=	A mail reader running inside Emacs or XEmacs

FETCH_ARGS=	-prR
GNU_CONFIGURE=	yes
USE_EMACS=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-emacs=${EMACS_CMD}
MAKE_ARGS=	prefix=${PREFIX} \
		lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME} \
		pixmapdir=${PREFIX}/${EMACS_LIBDIR_WITH_VER}/etc/vm

INFO=		vm vm-pcrisis

.include <bsd.port.mk>
