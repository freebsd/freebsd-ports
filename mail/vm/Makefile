# Created by: olive
# $FreeBSD$

PORTNAME=	vm
PORTVERSION=	8.1.2
PORTREVISION=	4
CATEGORIES=	mail elisp
MASTER_SITES=	https://launchpad.net/${PORTNAME}/8.1.x/${PORTVERSION}/+download/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail reader running inside Emacs or XEmacs

GNU_CONFIGURE=	yes
USE_EMACS=	yes
USES=		gmake makeinfo tar:tgz
CONFIGURE_ARGS+=	--with-emacs=${EMACS_CMD}
MAKE_ARGS=	prefix=${PREFIX} \
		lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME} \
		pixmapdir=${PREFIX}/${EMACS_LIBDIR_WITH_VER}/etc/vm

INFO=		vm vm-pcrisis

NO_STAGE=	yes

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
