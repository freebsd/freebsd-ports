# New ports collection makefile for:	Xaw3d
# Version required:	1.3
# Date created:		18 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.18 1998/09/21 01:33:22 steve Exp $
#

DISTNAME=	Xaw3d-1.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	widgets/Xaw3d/R6.1

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_IMAKE=	yes

post-extract:
	${MKDIR} ${WRKSRC}/X11/Xaw3d
	cd ${WRKSRC}/X11/Xaw3d; ln -sf ../../*.h .

post-install:
	if [ "${PORTOBJFORMAT}" = "aout" ]; then \
		${LN} -sf libXaw3d.so.6.1 ${PREFIX}/lib/libXaw3d.so; \
	fi
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/Xaw3d
	${CP} ${WRKSRC}/README.XAW3D ${PREFIX}/share/doc/Xaw3d

.include <bsd.port.mk>
