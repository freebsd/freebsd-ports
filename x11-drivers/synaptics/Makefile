# New ports collection makefile for:    synaptics
# Date created:				2004-01-02
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	synaptics
PORTVERSION=	0.14.6
PORTREVISION=	2
CATEGORIES=	x11-servers
MASTER_SITES=	http://web.telia.com/~u89404340/touchpad/files/:synaptics
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:synaptics \
		${X_DISTFILES:C/$/:x11/}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	The Synaptics touchpad X driver

BUILD_DEPENDS=	${X11BASE}/bin/X:${X_SERVER_PORT}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

X11VERSION!=	${MAKE} -C `${MAKE} -f bsd.port.mk -VX_SERVER_PORT` \
			-VPORTVERSION

.if	${X_WINDOW_SYSTEM:L} == xorg

MASTER_SITES+=	ftp://ftp.freedesktop.org/pub/xorg/individual/xserver/:x11 \
                http://xorg.freedesktop.org/releases/individual/xserver/:x11
DIST_SUBDIR=	xorg/xserver
X_DISTFILES=	xorg-server-${X11VERSION}.tar.bz2
PLIST_SUB+=	XORG="" XFREE86="@comment "
EXTRA_PATCHES=	${FILESDIR}/extra-xorg-server-1.4

post-patch:
	@${REINPLACE_CMD} 's|\(ALLINCLUDES = -I.\)|\1 -I${LOCALBASE}/include -I${LOCALBASE}/include/pixman-1|' \
		${WRKSRC}/Makefile

.elif	${X_WINDOW_SYSTEM:L} == xfree86-4

MASTER_SITES+=	${MASTER_SITE_XFREE:C/$/:x11/}
MASTER_SITE_SUBDIR=	${X11VERSION}/:x11
DIST_SUBDIR=	xc
X_DISTFILES=	XFree86-${X11VERSION}-src-3.tgz
PLIST_SUB+=	XORG="@comment " XFREE86=""

.else

BROKEN=		no support yet

.endif

MAKE_ENV=	TOP=${WRKDIR}/xc CFLAGSCLIENT="${CFLAGS}"

MAN1=		synclient.1 # syndaemon.1
MAN5=		synaptics.5
PORTDOCS=	COMPATIBILITY FILES INSTALL INSTALL.DE INSTALL.FR \
		README README.alps TODO

post-extract:
.for FILE in ${X_DISTFILES}
	@cd ${WRKDIR} && \
		${GZIP_CMD} -dc ${_DISTDIR}/${FILE} | ${TAR} -xf -
.endfor

.if	${X_WINDOW_SYSTEM:L} == xorg
pre-install:
	${MKDIR} ${X11BASE}/lib/xorg/modules/input/
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
