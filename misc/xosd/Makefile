# New ports collection makefile for:	xosd
# Date created:			2 May 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	xosd
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.ignavus.net/ \
		http://www3.kr.freebsd.org/~perky/distfiles/

MAINTAINER=	perky@fallin.lv

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.2:${PORTSDIR}/audio/xmms
.endif

XMMS_CONFIG?=	${X11BASE}/bin/xmms-config
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_GLIB=	yes
INSTALLS_SHLIB=	yes
MAKE_ENV=	CFLAGS='${CFLAGS}' PREFIX='${PREFIX}' \
		X11BASE='${X11BASE}' LOCALBASE='${LOCALBASE}' \
		GTK_CONFIG='${GTK_CONFIG}' GLIB_CONFIG="${GLIB_CONFIG}" \
		XMMS_CONFIG="${XMMS_CONFIG}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		osd_cat.1
MAN3=		xosd.3

.if defined(WITH_XMMS)
MAKE_ENV+=	XMMS_PLUGINDIR=${X11BASE}/lib/xmms
PLIST_SUB+=	WITH_XMMS=""
.else
PLIST_SUB+=	WITH_XMMS="@comment "
.endif

pre-build:
	${PERL} -pi -e "s@gcc@${CC}@g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
