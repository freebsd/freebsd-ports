# New ports collection makefile for:    synaptics
# Date created:				2004-01-02
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	synaptics
PORTVERSION=	0.14.4
PORTREVISION=	1
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

MASTER_SITES+=	${MASTER_SITE_XORG:C/$/:x11/}
MASTER_SITE_SUBDIR=	X11R${X11VERSION}/src/:x11
DIST_SUBDIR=	xorg
X_DISTFILES=	X11R${X11VERSION}-src3.tar.gz

.elif	${X_WINDOW_SYSTEM:L} == xfree86-4

MASTER_SITES+=	${MASTER_SITE_XFREE:C/$/:x11/}
MASTER_SITE_SUBDIR=	${X11VERSION}/:x11
DIST_SUBDIR=	xc
X_DISTFILES=	XFree86-${X11VERSION}-src-3.tgz

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

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
