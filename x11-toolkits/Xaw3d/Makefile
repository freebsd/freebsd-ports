# New ports collection makefile for:	Xaw3d
# Version required:	1.5
# Date created:		18 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.20 1998/11/14 09:43:29 asami Exp $
#

DISTNAME=	Xaw3d-1.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	widgets/Xaw3d/R6.3

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_IMAKE=	yes

.include <bsd.port.pre.mk>

post-extract:
	${MKDIR} ${WRKSRC}/X11/Xaw3d
	cd ${WRKSRC}/X11/Xaw3d; ln -sf ../../*.h .

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libXaw3d.so.6.1 ${PREFIX}/lib/libXaw3d.so
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/Xaw3d
	${CP} ${WRKSRC}/README.XAW3D ${PREFIX}/share/doc/Xaw3d

.include <bsd.port.post.mk>
