# New ports collection makefile for:	kseg
# Date created:		4 September 2001
# Whom:			Kuang-che Wu <kcwu@ck.tp.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	kseg
PORTVERSION=	0.401
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	math graphics
MASTER_SITES=	http://www.mit.edu/~ibaran/

MAINTAINER=	kcwu@csie.org
COMMENT=	A simulator of euclidean geometry

USE_QT_VER=	3
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

pre-patch:
	${REINPLACE_CMD} -e "s@\$$(QTDIR)@${QT_PREFIX}@; s@^CC =@#CC =@; s@-O2@${CFLAGS} ${PTHREAD_CFLAGS}@" ${WRKSRC}/Makefile ${WRKSRC}/formula/Makefile
	${REINPLACE_CMD} -e "s@-lqt@-lqt-mt ${PTHREAD_LIBS}@; " ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kseg ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/X11/kseg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/lib/X11/kseg
.for TRANS in cy de en es fr hu it ja nb nl pt tr
	${INSTALL_DATA} ${WRKSRC}/kseg_${TRANS}.qm ${PREFIX}/lib/X11/kseg
.endfor
.for TRANS in en es fr it ja nl pt tr
	${INSTALL_DATA} ${WRKSRC}/kseg_help_${TRANS}.html ${PREFIX}/lib/X11/kseg
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
