# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	7.22.20031103
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.sunet.se/pub/www/clients/Opera/unix/freebsd/722/final/en/static/ \
		ftp://sunsite.cnlab-switch.ch/mirror/opera/unix/freebsd/722/final/en/static/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/unix/freebsd/722/final/en/static/ \
		ftp://ftp.ntua.gr/pub/www/Opera/unix/freebsd/722/final/en/static/ \
		http://mirrors.pmmf.hu/mirror/opera/unix/freebsd/722/final/en/static/ \
		ftp://ftp.task.gda.pl/pub/opera/unix/freebsd/722/final/en/static/ \
		ftp://ftp.planetmirror.com/pub/opera/unix/freebsd/722/final/en/static/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/unix/freebsd/722/final/en/static/ \
		ftp://ftp.opera.com/pub/opera/unix/freebsd/722/final/en/static/

DISTNAME=	${PORTNAME}-${PORTVERSION:S/2./2-/}.1-static-qt.i386.freebsd-en

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

RESTRICTED=	"not redistributable; commercial software"
CONFLICTS=	linux-opera-*

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif

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
