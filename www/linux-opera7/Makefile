# New ports collection makefile for:		linux-opera7
# Date created:					17 February 2003
# Whom:						Mezz <reigncracks@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	7.11.20030429
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	http://snapshot.opera.com/unix/intel-linux/395-20030429-7.11-TP5/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.2/-2/}.1-static-qt.i386

MAINTAINER=	reigncracks@hotmail.com
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXm.so.2:${PORTSDIR}/x11-toolkits/linux-openmotif \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png

USE_BZIP2=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

.include <bsd.port.pre.mk>

.if exists(/etc/X11/applnk)
PLIST_SUB+=	APPLNK:=""
.else
PLIST_SUB+=	APPLNK:="@comment "
.endif

.if exists(${X11BASE}/share/gnome)
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

.if exists(${X11BASE}/share/applnk/Internet)
PLIST_SUB+=	KDE:=""
.else
PLIST_SUB+=	KDE:="@comment "
.endif

.if exists(${X11BASE}/share/applnk/Networking)
PLIST_SUB+=	KDE2:=""
.else
PLIST_SUB+=	KDE2:="@comment "
.endif

.if exists(${X11BASE}/share/gnome/apps)
PLIST_SUB+=	GNOMELNK:=""
.else
PLIST_SUB+=	GNOMELNK:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11PREFIX%%|${X11BASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/install.sh

do-install:
	(cd ${WRKSRC} && ./install.sh --prefix=${PREFIX})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
