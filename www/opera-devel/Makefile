# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	7.21.20031003
CATEGORIES=	www
MASTER_SITES=	http://snapshot.opera.com/unix/7.21-Preview-2/intel-freebsd/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/1./1-/}.1-static-qt.i386.freebsd

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

RESTRICTED=	"not redistributable; commercial software"

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

pre-everything:
	@${ECHO_MSG} '===> **************************************************'
	@${ECHO_MSG} '===> NOTE: The native version of Opera can not be'
	@${ECHO_MSG} '===> installed at the same time as linux-opera. If you'
	@${ECHO_MSG} '===> already have www/linux-opera installed, we'
	@${ECHO_MSG} '===> recommend you press Ctrl-C now and deinstall it.'
	@${ECHO_MSG} '===> **************************************************'

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11PREFIX%%|${X11BASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/install.sh

do-install:
	(cd ${WRKSRC} && ./install.sh --prefix=${PREFIX})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
