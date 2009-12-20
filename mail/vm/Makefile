# New ports collection makefile for: vm
# Date created: 	20 February 2002
# Whom:			olive
#
# $FreeBSD$
#

PORTNAME=	vm
PORTVERSION=	8.0.12
PORTREVISION=	1
CATEGORIES=	mail elisp
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	viewmail
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhein@timing.com
COMMENT=	A mail reader running inside Emacs or XEmacs

GNU_CONFIGURE=	yes
USE_EMACS=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-emacs=${EMACS_CMD}
MAKE_ARGS=	prefix=${PREFIX} \
		lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME} \
		pixmapdir=${PREFIX}/${EMACS_LIBDIR_WITH_VER}/etc/vm

INFO=		vm vm-pcrisis

.include <bsd.port.mk>
