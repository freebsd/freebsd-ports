# New ports collection makefile for:	itk
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	itk
PORTVERSION=	3.3
CATEGORIES=	x11-toolkits tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=incrtcl
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	[incr Tk] (A.K.A. "itk")

LIB_DEPENDS=	tk84:${PORTSDIR}/x11-toolkits/tk84 \
		itcl.${MAJOR}:${PORTSDIR}/lang/itcl

INSTALLS_SHLIB=	yes
MAKE_ENV+=	${PLIST_SUB} \
		SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

MAKEFILE=	${FILESDIR}/Makefile.lib
SHLIB_MAJOR=	${MAJOR}
SHLIB_MINOR=	${MINOR}
MAJOR=		${PORTVERSION:R}
MINOR=		${PORTVERSION:E}
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}
ITK_LIB=	libitk.so.${MAJOR}
.if defined(MAKE_JOBS)
MAKE_ARGS+=	-j${MAKE_JOBS}
.endif

MANN=		Archetype.n Toplevel.n Widget.n itk.n itkvars.n usual.n

ITK_LIB_FILE=	${ITK_LIB}.${SHLIB_MAJOR}

post-build:
	#
	# Consider running ``make test'' now, if the X11 environment
	# is available in this session
	#

test:
	cd ${WRKSRC} && ${SETENV} ITK_LIBRARY=${WRKSRC}/library \
		${PREFIX}/bin/wish8.4 tests/all.tcl -load "load ./${ITK_LIB}; package require Tk"

.include <bsd.port.mk>
