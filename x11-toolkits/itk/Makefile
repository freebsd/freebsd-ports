# New ports collection makefile for:	itk
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	itk
PORTVERSION=	${MAJOR}.${MINOR}
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=incrtcl
DISTNAME=	itcl${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	[incr Tk] (A.K.A. "itk")

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83 \
		itcl${MAJOR}${MINOR}.1:${PORTSDIR}/lang/itcl

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/itcl${MAJOR}.${MINOR}/itk
INSTALLS_SHLIB=	yes
MAKE_ENV+=	${PLIST_SUB} \
		SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

EXTRACT_AFTER_ARGS=| ${TAR} -xf - ./itcl${MAJOR}.${MINOR}/itk
MAKEFILE=	${FILESDIR}/Makefile.lib
SHLIB_MAJOR=	1
SHLIB_MINOR=	1
MAJOR=		3
MINOR=		2
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}
ITK_LIB=	libitk${MAJOR}${MINOR}.so
.if defined(MAKE_JOBS)
MAKE_ARGS+=	-j$(MAKE_JOBS)
.endif

MANCOMPRESSED=	no
MANN=		Archetype.n Toplevel.n Widget.n itk.n itkvars.n usual.n

ITK_LIB_FILE=	${ITK_LIB}.${SHLIB_MAJOR}

post-extract:
	${RM} ${WRKSRC}/pkgIndex.tcl

post-patch:
	${REINPLACE_CMD} \
		-e 's,package require Itk,load \
			[glob ${WRKSRC}/${ITK_LIB_FILE}*],;' \
		-e 's,return$$,exit,' ${WRKSRC}/tests/*
	${REINPLACE_CMD} \
		-e 's,\@itk_LIB_FILE\@,${ITK_LIB_FILE},' \
		${WRKSRC}/pkgIndex.tcl.in

.if defined(DISPLAY)
post-build test:
	cd ${WRKSRC} && ${SETENV} ITK_LIBRARY=${WRKSRC}/library \
		${PREFIX}/bin/wish8.3 tests/all.tcl
.endif

.include <bsd.port.mk>
