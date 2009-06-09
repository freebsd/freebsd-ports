# New ports collection makefile for:	Xaw3d
# Date created:		18 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	Xaw3d
PORTVERSION=	1.5E
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.visi.com/users/hawkeyd/X/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A 3-D Athena Widget set that looks like Motif

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_IMAKE=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xmu xt sm ice xpm

SUB_FILES=	pkg-message
SUB_LIST=	XAWVER="${XAWVER}"

.include <bsd.port.pre.mk>

post-extract:
	${MKDIR} ${WRKSRC}/X11/Xaw3d
	cd ${WRKSRC}/X11/Xaw3d; ${LN} -sf ../../*.h .

# Workaround a bug in egcs on FreeBSD/Alpha.
.if ${MACHINE_ARCH} == "alpha"
post-configure:
	@(cd ${WRKSRC}; ${MV} Makefile Makefile.orig; ${SED} -e \
	  's/CDEBUGFLAGS = -O/CDEBUGFLAGS =/g' Makefile.orig > Makefile)
.endif

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.XAW3D ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
