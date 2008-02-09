############################################################################
# New ports collection Makefile for:   RAPID
# Date created:        18 July 2006
# Whom:                Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#
#
############################################################################

PORTNAME=	rapid
PORTVERSION=	2.01
CATEGORIES=	math science graphics
MASTER_SITES=	http://www.cs.unc.edu/~geom/OBB/
DISTNAME=	RAPID201_MSVC

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Robust and Accurate Polygon Interference Detection

WRKSRC=		${WRKDIR}/RAPID201

RESTRICTED=	Must register to download at http://www.cs.unc.edu/~geom/OBB/OBBT.html

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

ALL_TARGET=

MAN1=	rapid.1

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	you must request a copy of ${DISTNAME}${EXTRACT_SUFX} from http://www.cs.unc.edu/~geom/OBB/OBBT.html, place it in ${DISTDIR}, and then run make again
.endif

post-extract:
	${REINPLACE_CMD} -E "s/friend RAPID_Collide/friend int RAPID_Collide/" ${WRKSRC}/RAPID_private.H

do-install:
	${MKDIR} ${PREFIX}/include/RAPID
	${INSTALL_DATA}	${WRKSRC}/*.H ${PREFIX}/include/RAPID
	${INSTALL_DATA}	${WRKSRC}/libRAPID.a ${PREFIX}/lib
	${INSTALL_MAN} ${FILESDIR}/rapid.1 ${PREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
