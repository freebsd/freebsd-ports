# New ports collection makefile for:	Xaw3d
# Date created:		18 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	Xaw3d
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	widgets/Xaw3d/R6.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3-D Athena Widget set that looks like Motif

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_IMAKE=	yes
INSTALLS_SHLIB=	yes

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} == xfree86-3
PLIST_FILES=	lib/libXaw3d.so.6
.endif

post-extract:
	${MKDIR} ${WRKSRC}/X11/Xaw3d
	cd ${WRKSRC}/X11/Xaw3d; ${LN} -sf ../../*.h .
	${SED} 's|%%XAWVER%%|${XAWVER}|g' ${MSG_FILE} > ${PKGMESSAGE}

# Workaround a bug in egcs on FreeBSD/Alpha.
.if ${MACHINE_ARCH} == "alpha"
post-configure:
	@(cd ${WRKSRC}; ${MV} Makefile Makefile.orig; ${SED} -e \
	  's/CDEBUGFLAGS = -O/CDEBUGFLAGS =/g' Makefile.orig > Makefile)
.endif

post-install:
	${MKDIR} ${PREFIX}/share/doc/Xaw3d
	${CP} ${WRKSRC}/README.XAW3D ${PREFIX}/share/doc/Xaw3d
.if ${X_WINDOW_SYSTEM:L} == xfree86-3
	${LN} -sf libXaw3d.so.${XAWVER} ${X11BASE}/lib/libXaw3d.so.6
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
