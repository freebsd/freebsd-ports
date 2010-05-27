# New ports collection makefile for:	diffutils
# Date created:				5 September 2001
# Whom:				Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#

PORTNAME=	diffutils
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	diffutils

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The GNU diff utilities

LIB_DEPENDS=	sigsegv:${PORTSDIR}/devel/libsigsegv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

INFO=		diff
MAN1=		gcmp.1 gdiff.1 gdiff3.1 gsdiff.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
