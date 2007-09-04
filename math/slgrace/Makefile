# New ports collection makefile for:	slgrace
# Date created:		2007-08-30
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	slgrace
PORTVERSION=	0.2.1
CATEGORIES=	math devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v${SLANG_VER}/modules/grace/ \
		ftp://ftp.fu-berlin.de/pub/unix/misc/slang/v${SLANG_VER}/modules/grace/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	garga/slgrace/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A SLang module to plot graphs with grace

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2
RUN_DEPENDS=	grace:${PORTSDIR}/math/grace

SLANG_VER=	2.1

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/slang/v2/modules/grace-module.so.${PORTVERSION} \
		lib/slang/v2/modules/grace-module.so \
		share/slsh/local-packages/help/grace.hlp \
		share/slsh/local-packages/grace.sl

.include <bsd.port.mk>
