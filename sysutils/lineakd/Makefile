# New ports collection makefile for: lineakd
# Date created:				03 June 2002
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	lineakd
PORTVERSION=	0.4.p3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=lineak
DISTNAME=	${PORTNAME}-0.4pre3

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Lineakd is a daemon which enables special keys on internet keyboards

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext

USE_BISON=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	-I${X11BASE}/include

.include <bsd.port.pre.mk>

EXTRA_PATCHES=  ${FILESDIR}/extra-patch-lineakd.c-4

.if ${OSVERSION} >= 500000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-lineakd.c-5
.endif

.include <bsd.port.post.mk>
