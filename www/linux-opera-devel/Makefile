# New ports collection makefile for:		linux-opera
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	7.11.20030515
PORTREVISION=	2
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/linux/711/final/en/i386/static/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.2/-2/}.1-static-qt.i386

MAINTAINER=	mezz7@cox.net
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

RESTRICTED=	"not redistributable; commercial software"

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXm.so.2:${PORTSDIR}/x11-toolkits/linux-openmotif

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
