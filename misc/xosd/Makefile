# New ports collection makefile for:	xosd
# Date created:			2 May 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	xosd
PORTVERSION=	0.7.0
CATEGORIES=	misc
MASTER_SITES=	http://www.ignavus.net/ \
		http://www3.kr.freebsd.org/~perky/distfiles/

MAINTAINER=	perky@python.or.kr

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.1:${PORTSDIR}/audio/xmms
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
MAKE_ENV=	CFLAGS='${CFLAGS}' PREFIX='${PREFIX}'

MAN1=		osd_cat.1
MAN3=		xosd.3

.if defined(WITH_XMMS)
MAKE_ENV+=	XMMS_PLUGINDIR=${X11BASE}/lib/xmms
PLIST_SUB+=	WITH_XMMS=""
.else
PLIST_SUB+=	WITH_XMMS="@comment "
.endif

.include <bsd.port.mk>
